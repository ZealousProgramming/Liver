//#include "sellas.h"
#include "../framework/sellas.h"

#include <iostream>

// ---- Forward Declarations ----
void start();
void tick(f32 delta_time);
void render(f32 delta_time);

int main() {
	const i16 WINDOW_WIDTH = 640;
	const i16 WINDOW_HEIGHT = 360;
	const char* WINDOW_TITLE = "Sellas Application";

	Sellas::Application* app = new Sellas::Application();

	app->on_start_fn = &start;
	app->on_tick_fn = &tick;
	app->on_render_fn = &render;

	if (!app->initialize(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
		std::cout << "[Game] ERROR: Application failed the initialize!\n";
		return -1;
	}

	app->run();

	app->shutdown();

	delete app;
	return 0;
}

void start() {
	std::cout << "[Game] Starting game loop..\n";
}

void tick(f32 delta_time) {
	std::cout << "[Game] Ticking..\n";
}

void render(f32 delta_time) {
	std::cout << "[Game] Rendering..\n";
}
