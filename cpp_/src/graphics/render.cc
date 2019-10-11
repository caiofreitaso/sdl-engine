#include <game-engine/graphics/render.h>

namespace {
	double m_fps = 0.0f;
	double m_deltaTime = 0.0f;

	unsigned m_count = 0;
	unsigned m_time = 0;
	unsigned m_diff = 0;
}

double Engine::Graphics::fps() { return m_fps; }
double Engine::Graphics::dTime() { return m_deltaTime; }
unsigned Engine::Graphics::frameCount() { return m_count; }
unsigned Engine::Graphics::time() { return m_time; }
unsigned Engine::Graphics::diff() { return m_diff; }

void
Engine::Graphics::initGL()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0,0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void
Engine::Graphics::clear()
{
	IO::Resolution size = IO::windowSize();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, size.width, size.height);
}

void
Engine::Graphics::camera(Camera cam)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (cam.perspective)
	{
		float ratio = IO::windowRatio();
		float fov   = (360/3.14159265) * atan(tan(cam.v_fov*3.14159265/180) * ratio);

		gluPerspective(fov, ratio, cam.near, cam.far);
		gluLookAt(cam.position[0], cam.position[1], cam.position[2],
				  cam.target[0]  , cam.target[1]  , cam.target[2],
				  cam.up[0]      , cam.up[1]      , cam.up[2]);
	} else
		glOrtho(cam.left, cam.right, cam.bottom, cam.top, cam.near, cam.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void
Engine::Graphics::update()
{
	unsigned actual = SDL_GetTicks();

	m_diff      = actual - m_time;
	m_deltaTime = ((double)(m_diff))/1000.0;
	m_fps       = 1/m_deltaTime;
	m_time  = actual;
	m_count++;
}

void
Engine::Graphics::render(Camera cam, unsigned VAO, std::vector<MeshGL> const& objects)
{
	clear();
	camera(cam);

	glBindVertexArray(VAO);
	
	for(auto& i : objects)
	{
		glBindBuffer(GL_ARRAY_BUFFER, i.VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i.EBO);
		
		glEnable(GL_PRIMITIVE_RESTART);
		glPrimitiveRestartIndex(i.reset);
		
		glDrawElements(GL_TRIANGLE_STRIP, i.EBO_size, GL_UNSIGNED_INT, 0);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	IO::swapWindow();

	update();	
}
