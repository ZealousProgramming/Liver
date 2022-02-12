//#include "sellas.h"
#include "../framework/sellas.h"

// ---- Forward Declarations ----
void start();
void cleanup();
void tick(f32 delta_time);
void render(f32 delta_time);

// ---- Test Data
Ref<Sellas::Texture> test_texture;

// --- Functions
int main(int argc, char** argv) {
	constexpr i16 WINDOW_WIDTH = 640;
	constexpr i16 WINDOW_HEIGHT = 360;
	const char* WINDOW_TITLE = "Sellas Application";

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

	if (auto texture = Sellas::Texture::create_texture()) {
		test_texture = texture.value();
		//test_texture->initialize("../../assets/textures/s_guy.png");
		test_texture->initialize("../../../assets/textures/s_guy.png");
	}

}

void cleanup() {
	std::cout << "[Game] Cleaning up..\n";
	test_texture->shutdown();
	auto _count = test_texture.use_count();
}

void tick(f32 delta_time) {
	//std::cout << "[Game] Ticking..\n";

}

void render(f32 delta_time) {
	//std::cout << "[Game] Rendering..\n";
	test_texture->bind();
	
}
