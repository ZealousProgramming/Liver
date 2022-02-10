//#include "sellas.h"
#include "../framework/sellas.h"

// Data
f32 vertices[] = {
	-0.5f,  -0.5f,  0.0f, // Vertex 1
	 0.5f,  -0.5f,  0.0f, // Vertex 2
	 0.0f,	 0.5f,  0.0f  // Vertex 3
};

// ---- Forward Declarations ----
void start();
void cleanup();
void tick(f32 delta_time);
void render(f32 delta_time);


int main(int argc, char** argv) {
	constexpr i16 WINDOW_WIDTH = 640;
	constexpr i16 WINDOW_HEIGHT = 360;
	constexpr char* WINDOW_TITLE = "Sellas Application";

	Owned<Sellas::Application> app = std::make_unique<Sellas::Application>();


	app->setup_lifecycle_events(&start, &cleanup, &tick, &render);

	if (!app->initialize(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
		std::cout << "[Game] ERROR: Application failed the initialize!\n";
		return -1;
	}

	app->run();

	app->shutdown();
	app.release();

	return 0;
}

void start() {
	std::cout << "[Game] Starting game loop..\n";
}

void cleanup() {
	std::cout << "[Game] Cleaning up..\n";
}

void tick(f32 delta_time) {
	//std::cout << "[Game] Ticking..\n";
}

void render(f32 delta_time) {
	//std::cout << "[Game] Rendering..\n";
}
