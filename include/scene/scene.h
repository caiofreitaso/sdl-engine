#ifndef SCENE_H
#define SCENE_H

#include "../game.h"
#include "../render/render.h"
#include "../render/light.h"
#include "../contiguous.h"
#include "../vertex.h"

struct scene;

typedef void (*SceneUpdate)(struct scene*);

typedef struct {
	unsigned char keys [282];
	unsigned char mouse[3];
	unsigned char clicks;
	unsigned scroll_time;
	int scroll;
	int mouse_x;
	int mouse_y;
} input_state_t;

typedef struct {
	input_state_t input;
	void *object;
} SceneState;

typedef void (*EventHandler)(SDL_Event, SceneState*);

typedef struct scene
{
	GLuint  VAO;
	array_t meshes;

	camera_t camera;
	SDL_bool end;

	SceneUpdate  update;

	EventHandler event_handler;
	SceneState   state;
} scene_t;

void scene_init(scene_t*);
void scene_attach(scene_t*, array_t VBO, array_t EBO, GLuint idx);
void scene_destroy(scene_t*);
void scene_render(scene_t);
void scene_event(scene_t*);
void scene_loop(scene_t*);
void scene_loopMP(scene_t*);


void nop_handler(SDL_Event, SceneState*);
void basic_handler(SDL_Event, scene_t*);

void WASD_update(scene_t*);

#endif