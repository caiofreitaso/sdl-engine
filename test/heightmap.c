#include <SDL.h>
#include <GL/gl.h>
#include "../include/point.h"
#include "../include/game.h"

int main(int argc, char const *argv[])
{
	point3_t vertices[9];
	GLuint   indices [14] = {0,3,1,4,2,5,5,3,3,6,4,7,5,8};
	unsigned i,j;

	for(i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			vertices[i*3+j].v[0] = i;
			vertices[i*3+j].v[1] = (i+1)*(j+1);
			vertices[i*3+j].v[2] = j;
		}

	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1,&vao);
	glGenBuffers(1,&vbo);
	glGenBuffers(1,&ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		9 * sizeof(point3_t),
		vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		14 * sizeof(GLuint),
		indices, GL_STATIC_DRAW);

	Game game; 

	game.settings.display.resolution.width = 1024;
	game.settings.display.resolution.height = 768;
	game.settings.display.mode = WINDOW;

	if (!game_init("TEST", &game))
	{
		glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(game.window);
		SDL_Delay(1000);
	}

	game_quit(&game);

	return 0;
}