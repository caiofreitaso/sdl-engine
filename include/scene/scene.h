#ifndef SCENE_H
#define SCENE_H

#include "../game.h"
#include "../render/render.h"
#include "../contiguous.h"
#include "../vertex.h"

typedef void (*EventHandler)(SDL_Event, void*);

typedef struct 
{
	GLuint VAO;
	array_t meshes;

	EventHandler event_handler;
	void* event_object;
} scene_t;

void scene_init(scene_t*);
void scene_attach(scene_t*, array_t VBO, array_t EBO, GLuint idx);
void scene_destroy(scene_t*);
void scene_render(scene_t, camera_t);

#endif