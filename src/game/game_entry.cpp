//#include "sellas.h"
#include "../framework/sellas.h"

// ---- Forward Declarations ----
void start();
void cleanup();
void tick(f32 delta_time);
void render(f32 delta_time);

// ---- Test Data
Ref<Sellas::Texture> test_texture;
Ref<Sellas::Camera> main_camera;
f32 camera_speed = 10.0f;

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

	main_camera = std::make_shared<Sellas::Camera>();

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
	
	f32 h_velocity = Sellas::Input::is_key_pressed(Sellas::Key::KEY_RIGHT) - 
		Sellas::Input::is_key_pressed(Sellas::Key::KEY_LEFT);

	f32 v_velocity = Sellas::Input::is_key_pressed(Sellas::Key::KEY_UP) - 
		Sellas::Input::is_key_pressed(Sellas::Key::KEY_DOWN);

	glm::vec3 velocity = glm::vec3(h_velocity, v_velocity, 0.0f) * delta_time;

	main_camera->get_mut_transform().translate(velocity);
}

void render(f32 delta_time) {
	//std::cout << "[Game] Rendering..\n";
	test_texture->bind();
	
}
