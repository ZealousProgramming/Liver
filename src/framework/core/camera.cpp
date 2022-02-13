#include "camera.h"

namespace Sellas {
	u8 Camera::camera_count = 0;
	Camera* Camera::current_camera = nullptr;

	Camera::Camera() {
		transform = Transform(glm::vec3(0.0f, 0.0f, -3.0f));
		current = false;
		camera_type = CameraType::PERSPECTIVE;
		near_plane = 0.01f;
		far_plane = 100.0f;

		if (camera_count > 0) return;

		current = true;
		Camera::current_camera = this;
		camera_count += 1;
		// TODO(devon): Manage the cameras(remove id of cameras 
		// that leave the scene and fill in the gaps)
		id = camera_count;

	}

	void Camera::make_current() {
		if (Camera::current_camera != nullptr) {
			Camera::current_camera->not_current();
		}
		
		current = true;
		Camera::current_camera = this;
	}

	void Camera::not_current() {
		current = false;
	}
	
	void Camera::set_transform(const Transform& new_transform) {
		transform = new_transform;
	}

}