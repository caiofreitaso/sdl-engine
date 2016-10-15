#include "../include/game.h"
#include "../include/render/heightmap.h"
#include "../include/render/light.h"
#include "../include/scene/scene.h"
#include "../include/world/map.h"

int main( int argc, char* args[] )
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	map_t map;
	heightmap_t hm;

	map_read(&map, args[1]);
	heightmap_init(&hm, &map);

	if (!game_init("Cerebrate Test"))
	{
		scene_t s;

		render_init();
		scene_init(&s);

		light_set(DEFAULT_LIGHT, 0);

		scene_attach(&s, hm.vertices, hm.indices, hm.r_index);
		heightmap_free(hm);

		while(1)
		{
			scene_render(s, DEFAULT_CAMERA);
			printf("#%d : %f fps -- %f s/f\n",
					RENDERER.lastTime, RENDERER.fps, RENDERER.deltaTime);
		}
		scene_destroy(&s);
	}
	game_quit();

	return 0;
}