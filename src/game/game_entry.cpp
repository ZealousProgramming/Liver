#include "../framework/liver.h"

// ---- Forward Declarations ----
void start();
void cleanup();
void tick(f32 delta_time);
void render(f32 delta_time);


constexpr i16 WINDOW_WIDTH = 640;
constexpr i16 WINDOW_HEIGHT = 360;
const char* WINDOW_TITLE = "Liver Application";

// ---- Test Data
Ref<Liver::Texture> test_texture;
Ref<Liver::Camera> main_camera;
//f32 camera_speed = 0.1f;
f32 camera_speed = 1.1f;

// --- Functions
int main(int argc, char** argv) {
		Owned<Liver::Application> app = std::make_unique<Liver::Application>();


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
	
	// - Test Data -
	// -------------
	f32 aspect_ratio = WINDOW_WIDTH / (1.0f * WINDOW_HEIGHT);
	f32 fov = 60.0f;
	f32 near_plane = 0.1f;
	f32 far_plane = 100.0f;

	main_camera = std::make_shared<Liver::Camera>();
	main_camera->set_projection_perspective(fov, aspect_ratio, near_plane, far_plane);

	if (auto texture = Liver::Texture::create_texture()) {
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
	
	f32 h_velocity = Liver::Input::is_key_pressed(Liver::Key::KEY_RIGHT) - 
		Liver::Input::is_key_pressed(Liver::Key::KEY_LEFT);

	f32 v_velocity = Liver::Input::is_key_pressed(Liver::Key::KEY_UP) - 
		Liver::Input::is_key_pressed(Liver::Key::KEY_DOWN);

	//glm::vec3 velocity = glm::vec3(h_velocity, v_velocity, 0.0f) * delta_time;

	auto forward_vector = main_camera->get_transform().get_forward();
	main_camera->get_mut_transform().translate(v_velocity * camera_speed * forward_vector * delta_time);
}

void render(f32 delta_time) {
	//std::cout << "[Game] Rendering..\n";
	test_texture->bind();
	
}
