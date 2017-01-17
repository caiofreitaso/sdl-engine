#include "../include/scene/scene.h"

void scene_init(scene_t* s)
{
	glGenVertexArrays(1, &(s->VAO));
	array_init(&s->meshes, sizeof(mesh_t));
	s->state.input.scroll = 0;
}

void scene_destroy(scene_t* s)
{
	FOR_EACH(mesh_t, m, s->meshes)
		glDeleteBuffers(1, &(m->VBO));
		glDeleteBuffers(1, &(m->EBO));
	END_FOR
	
	glDeleteVertexArrays(1, &(s->VAO));
	
	array_free(s->meshes);
}

void scene_attach(scene_t* s, array_t VBO, array_t EBO, GLuint idx)
{
	mesh_t mesh;
	mesh.reset = idx;
	mesh.EBO_size = EBO.size;

	glGenBuffers(1, &(mesh.VBO));
	glGenBuffers(1, &(mesh.EBO));

	glBindVertexArray(s->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
	glBufferData(GL_ARRAY_BUFFER,
		VBO.size * sizeof(vertex_t),
		VBO.array, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)offsetof(vertex_t,normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)offsetof(vertex_t,color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		EBO.size * sizeof(unsigned),
		EBO.array, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	array_add(&(s->meshes), &mesh);
}

void scene_render(scene_t s)
{
	render_clear();
	render_camera(s.camera);

	glBindVertexArray(s.VAO);
	
	FOR_EACH(mesh_t, m, s.meshes)
		glBindBuffer(GL_ARRAY_BUFFER, m->VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->EBO);
		
		glEnable(GL_PRIMITIVE_RESTART);
		glPrimitiveRestartIndex(m->reset);
		
		glDrawElements(GL_TRIANGLE_STRIP, m->EBO_size, GL_UNSIGNED_INT, 0);
	END_FOR

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	SDL_GL_SwapWindow(GAME.window);

	render_update();

	printf("#%llu : %.2lf fps\t%lf s/f  %.1f,%.1f,%.1f SCROLL=%d %.0fdeg %ddiff\n",
		RENDERER.lastTime, RENDERER.fps, RENDERER.deltaTime,
		s.camera.position.x,s.camera.position.y,s.camera.position.z,
		s.state.input.scroll, s.camera.v_fov,
		RENDERER.lastTime - s.state.input.scroll_time);

	//glDisableClientState(GL_VERTEX_ARRAY);
}

void scene_event(scene_t *s)
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_WINDOWEVENT:
			case SDL_QUIT:
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
				basic_handler(e, s);
				break;
			default:
				s->event_handler(e, &s->state);
				break;
		}
	}
}

void scene_loop(scene_t *s)
{
	while (!s->end)
	{
		scene_event(s);
		s->update(s);
		scene_render(*s);
	}
}

void scene_loopMP(scene_t *s)
{
	#pragma omp parallel
	{
		#pragma omp master
		while (!s->end)
		{
			s->update(s);
			scene_render(*s);
			if (RENDERER.diffTime <= GAME.settings.render_delay)
				SDL_Delay(GAME.settings.render_delay);
		}

		#pragma omp single
		while (!s->end)
		{
			scene_event(s);
			SDL_Delay(GAME.settings.event_delay);
		}

	}
}

void nop_handler(SDL_Event e, SceneState* o)
{
}

void basic_handler(SDL_Event e, scene_t* s)
{
	switch(e.type)
	{
		case SDL_WINDOWEVENT:
			switch(e.window.event)
			{
				case SDL_WINDOWEVENT_RESIZED:
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					GAME.settings.video.size.width  = e.window.data1;
					GAME.settings.video.size.height = e.window.data2;
					break;
			}
			break;
		
		case SDL_QUIT:
			GAME.quit = SDL_TRUE;
			s->end    = SDL_TRUE;
			break;
		
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			s->state.input.keys[e.key.keysym.scancode] = e.key.state;
			break;
		
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			switch(e.button.button)
			{
				case SDL_BUTTON_LEFT:   s->state.input.mouse[0] = e.button.state; break;
				case SDL_BUTTON_MIDDLE: s->state.input.mouse[1] = e.button.state; break;
				case SDL_BUTTON_RIGHT:  s->state.input.mouse[2] = e.button.state; break;
			}
			s->state.input.clicks  = e.button.clicks;
			s->state.input.mouse_x = e.button.x;
			s->state.input.mouse_y = e.button.y;
			break;

		case SDL_MOUSEWHEEL:
			s->state.input.scroll      = e.wheel.y;
			s->state.input.scroll_time = e.wheel.timestamp;
			break;
	}
}

void WASD_update(scene_t* s)
{
	if (s->state.input.keys[SDL_SCANCODE_W] == SDL_PRESSED)
	{
		s->camera.position.y += GAME.settings.controls.cam_speed * RENDERER.deltaTime;
		s->camera.target.y   += GAME.settings.controls.cam_speed * RENDERER.deltaTime;
	}

	if (s->state.input.keys[SDL_SCANCODE_A] == SDL_PRESSED)
	{
		s->camera.position.x -= GAME.settings.controls.cam_speed * RENDERER.deltaTime;
		s->camera.target.x   -= GAME.settings.controls.cam_speed * RENDERER.deltaTime;
	}

	if (s->state.input.keys[SDL_SCANCODE_S] == SDL_PRESSED)
	{
		s->camera.position.y -= GAME.settings.controls.cam_speed * RENDERER.deltaTime;
		s->camera.target.y   -= GAME.settings.controls.cam_speed * RENDERER.deltaTime;
	}

	if (s->state.input.keys[SDL_SCANCODE_D] == SDL_PRESSED)
	{
		s->camera.position.x += GAME.settings.controls.cam_speed * RENDERER.deltaTime;
		s->camera.target.x   += GAME.settings.controls.cam_speed * RENDERER.deltaTime;
	}

	if (s->state.input.keys[SDL_SCANCODE_E] == SDL_PRESSED)
		s->camera.v_fov++;
	if (s->state.input.keys[SDL_SCANCODE_Q] == SDL_PRESSED)
		s->camera.v_fov--;

	if (RENDERER.lastTime - s->state.input.scroll_time <= GAME.settings.event_delay)
	{
		float newpos = s->camera.position.z - (s->state.input.scroll * GAME.settings.controls.cam_scroll * RENDERER.deltaTime);

		if (newpos > 200)
		{
			s->camera.position.z = 200;
			s->camera.target.z   = 200 - cos(3.14159265/18);
		}
		else if (newpos < 100)
		{
			s->camera.position.z = 100;
			s->camera.target.z   = 100 - cos(3.14159265/18);
		}
		else
		{
			s->camera.position.z -= s->state.input.scroll * GAME.settings.controls.cam_scroll * RENDERER.deltaTime;
			s->camera.target.z   -= s->state.input.scroll * GAME.settings.controls.cam_scroll * RENDERER.deltaTime;
		}

//		if (RENDERER.lastTime - s->state.input.scroll_time > 1000)
//		{
//			s->state.input.scroll = 0;
//			s->state.input.scroll_time = RENDERER.lastTime;
//		}
	}		
}