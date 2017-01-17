#include "../include/game/game.h"
#include "../include/map/heightmap.h"
#include "../include/graphics/light.h"
#include "../include/scene/scene.h"

int main( int argc, char* args[] )
{
	unsigned random = (argc == 1);

	map_t map;
	heightmap_t hm;

	if (random)
	{
		unsigned terrains[8] = {27,26,21,11,6,5,1,0};

		srand(time(NULL));

		map.x     = 800;
		map.y     = 800;
		map.field = (map_point_t*) malloc(sizeof(map_point_t) * map.x * map.y);
		map.areas = 0;
		array_init(&map.doodads, sizeof(char));

		unsigned i,j,k;

		//#pragma omp parallel for
		for (i = 0; i < map.x; i++)
			for (j=0; j< map.y; j++)
		{
			map.field[i*map.x+j].height  = rand()%256;
			map.field[i*map.x+j].terrain = terrains[rand() % 6];
		}

	} else
		map_read(&map, args[1]);
	
	heightmap_init(&hm, &map);

	if (!game_init("Cerebrate Test"))
	{
		scene_t s;
		s.end = SDL_FALSE;
		s.event_handler = nop_handler;
		s.update = WASD_update;

		s.camera = DEFAULT_CAMERA;
		s.camera.target.x = s.camera.position.x = s.camera.position.y = 0;
		s.camera.position.z = 100.0;

		float angleDown = 10;
		
		s.camera.target.y = sin(angleDown*3.14159265/180);
		s.camera.target.z = s.camera.position.z - cos(angleDown*3.14159265/180);
		s.camera.v_fov = 20;

		render_init();
		light_set(DEFAULT_LIGHT, 0);

		scene_init(&s);
		scene_attach(&s, hm.vertices, hm.indices, hm.r_index);
		heightmap_free(hm);

		while(!GAME.quit)
		{
			scene_loopMP(&s);
		}
		scene_destroy(&s);
	}
	game_quit();

	return 0;
}