#pragma once

#include "common.h"
#include "../../core/math/math.h"

namespace Sellas {
	class Camera {
		public:
			enum class CameraType {
				PERSPECTIVE = 1,
				ORTHO = 2
			};
		public:
			Camera();
			~Camera() = default;

			void make_current();
			void not_current();

			void set_camera_type(const CameraType new_type) { camera_type = new_type; }
			void set_transform(const Transform& new_transform);

			const u16 get_id() const { return id; }
			const f32 get_near() const { return near_plane; }
			const f32 get_far() const { return far_plane;  }

			const Transform get_transform() const { return transform; }
			Transform& get_mut_transform() { return transform; }

			const CameraType get_camera_type() const { return camera_type; }

			static Camera* current_camera;
		private:
			Transform transform;

			bool current;
			u16 id;
			f32 near_plane;
			f32 far_plane;


			CameraType camera_type;

			static u8 camera_count;
	};
}