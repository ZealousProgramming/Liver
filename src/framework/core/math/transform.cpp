#include "transform.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Sellas {

	Transform::Transform() {
		translation = glm::mat4(1.0f);
		rotation = glm::mat4(1.0f);
		scalar = glm::mat4(1.0f);
	}

	Transform::Transform(const glm::vec3 position) {
		translation = glm::mat4(1.0f);
		rotation = glm::mat4(1.0f);
		scalar = glm::mat4(1.0f);

		translation = glm::translate(translation, position);
	}

	void Transform::translate(const glm::vec3 delta_position) {
		translation = glm::translate(translation, delta_position);
	}

	void Transform::rotate_deg(const f32 angle_degrees, const glm::vec3 axis) {
		glm::tquat quat = glm::tquat(rotation);
		quat = glm::rotate(quat, glm::radians(angle_degrees), axis);
		rotation = glm::toMat4(quat);
		//matrix = glm::rotate(matrix, glm::radians(angle_degrees), axis);
	}

	void Transform::rotate_rad(const f32 angle_radians, const glm::vec3 axis) {
		//matrix = glm::rotate(matrix, angle_radians, axis);
		glm::tquat quat = glm::tquat(rotation);
		quat = glm::rotate(quat, angle_radians, axis);
		rotation = glm::toMat4(quat);
	}

	void Transform::scale(const glm::vec3 scalar_vector) {
		scalar = glm::scale(scalar, scalar_vector);
	}

	void Transform::set_position(const glm::vec3 position) {
		translation = glm::translate(glm::mat4(1.0f), position);
	}

	void Transform::set_scale(const glm::vec3 scalar_vector) {
		scalar = glm::scale(glm::mat4(1.0f), scalar_vector);
	}


}