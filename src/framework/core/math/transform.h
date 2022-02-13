#pragma once

#include "../common.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Sellas {
	class Transform {
		public:
			Transform();
			Transform(const glm::vec3 position);
			~Transform() = default;

			void translate(const glm::vec3 delta_position);
			void rotate_deg(const f32 angle_degrees, const glm::vec3 axis);
			void rotate_rad(const f32 angle_radians, const glm::vec3 axis);
			void scale(const glm::vec3 scalar_vector);


			void set_position(const glm::vec3 position);
			void set_scale(const glm::vec3 scalar_vector);

			const glm::vec3 get_position() const { return glm::vec3(translation[0][3], translation[1][3], translation[2][3]); }
			const glm::vec3 get_scale() const { return glm::vec3(scalar[0][0], scalar[1][1], scalar[2][2]); }
			const glm::vec3 get_euler_angles() const { return glm::eulerAngles(glm::tquat(rotation)); }
			const f32 get_roll_rad() const { return glm::roll(glm::tquat(rotation)); }
			const f32 get_yaw_rad() const { return glm::yaw(glm::tquat(rotation)); }
			const f32 get_pitch_rad() const { return glm::pitch(glm::tquat(rotation)); }
			const f32 get_roll_deg() const { return glm::degrees(glm::roll(glm::tquat(rotation))); }
			const f32 get_yaw_deg() const { return glm::degrees(glm::yaw(glm::tquat(rotation))); }
			const f32 get_pitch_deg() const { return glm::degrees(glm::pitch(glm::tquat(rotation))); }
			
			//const glm::mat4 get_translation_matrix() const { return translation; }
			//const glm::mat4 get_scale_matrix() const { return scalar; }
			//const glm::mat4 get_rotation_matrix() const { return rotation; }
			const glm::mat4 get_matrix() const { return translation * rotation * scalar; }

		private:
			glm::mat4 translation;
			glm::mat4 rotation;
			glm::mat4 scalar;

	
	};
}

