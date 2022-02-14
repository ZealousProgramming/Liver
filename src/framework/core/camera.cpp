#include "camera.h"

namespace Liver {
	u8 Camera::camera_count = 0;
	Camera* Camera::current_camera = nullptr;

	Camera::Camera() {
		transform = Transform(glm::vec3(0.0f, 0.0f, -3.0f));
		current = false;
		projection_type = ProjectionType::PERSPECTIVE;
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

	void Camera::set_projection_perspective(const f32 fov_deg, const f32 aspect_ratio, const f32 near_plane, const f32 far_plane) {
		this->near_plane = near_plane;
		this->far_plane = far_plane;
		this->aspect_ratio = aspect_ratio;
		this->fov = fov_deg;
		projection = glm::perspective(glm::radians(fov_deg), aspect_ratio, near_plane, far_plane);
	}

	void Camera::set_projection_orthographic(const f32 left, const f32 right, const f32 bottom, const f32 top) {
		projection = glm::ortho(left, right, bottom, top);
	}

	void Camera::set_projection(const glm::vec2 window_size) {
		auto half_size = window_size / 2.0f;
		projection = glm::ortho(-half_size.x, half_size.x, half_size.y, -half_size.y);
	}

}