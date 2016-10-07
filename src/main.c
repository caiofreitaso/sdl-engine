#include "../include/game.h"
#include "../include/render/heightmap.h"
#include "../include/render/light.h"
#include "../include/world/map.h"

int main( int argc, char* args[] )
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	Game game;

	game.settings.display.resolution.width = 1024;
	game.settings.display.resolution.height = 768;
	game.settings.display.mode = WINDOW;

	map_t map;
	heightmap_t hm;

	map_read(&map, args[1]);
	heightmap_init(&hm, map);

	if (!game_init("Cerebrate Test", &game))
	{
		render_init();
		heightmap_gl(&hm);
		light_set(DEFAULT_LIGHT, 0);
		while(1)
		{
			render_clear();
			render_camera(DEFAULT_CAMERA);
			heightmap_render(hm);
			if (render_update())
				printf("#%d : %f fps -- %f s/f\n",
					RENDERER.lastTime, RENDERER.fps, RENDERER.deltaTime);
			SDL_GL_SwapWindow(game.window);
		}
	}

	heightmap_destroy(&hm);
	render_destroy();
	game_quit(&game);

	return 0;
}