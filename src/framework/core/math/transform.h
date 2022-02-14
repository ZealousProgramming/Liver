#pragma once

#include "../common.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Liver {
	class Transform {
		public:
			Transform();
			Transform(const glm::vec3 position);
			~Transform() = default;
			
			/**
				Translates the transform by 'delta_position' units.

				@param delta_position The amount of units to translate.
			*/
			void translate(const glm::vec3 delta_position);

			/**
				Rotates the transform by `angle_degrees` along `axis`.

				@param angle_degrees The angle (in degrees) to rotate the transform by.
				@param axis The axis to rotate the transform along.
			*/
			void rotate_deg(const f32 angle_degrees, const glm::vec3 axis);

			/**
				Rotates the transform by `angle_radians` along `axis`.

				@param angle_radians The angle (in radians) to rotate the transform by.
				@param axis The axis to rotate the transform along.
			*/
			void rotate_rad(const f32 angle_radians, const glm::vec3 axis);

			/**
				Scales the transform's current scale by `scalar_vector`.

				@param scalar_vector The scalar to scale the transform by.
			*/
			void scale(const glm::vec3 scalar_vector);

			/**
				Sets the position of the transform to the desired `position`.

				@param position The desired position.
			*/
			void set_position(const glm::vec3 position);

			/**
				Sets the scale of the transform to the desired `scalar_vector`.

				@param scalar_vector The desired scale.
			*/
			void set_scale(const glm::vec3 scalar_vector);
			
			/**
				Returns the position of the Transform in vec3 representation.

				@return Returns the position of the transform in vec3 representation.
			*/
			const glm::vec3 get_position() const { return glm::vec3(translation[0][3], translation[1][3], translation[2][3]); }

			/**
				Returns the scale of the Transform in vec3 representation.

				@return Returns the scale of the transform in vec3 representation.
			*/
			const glm::vec3 get_scale() const { return glm::vec3(scalar[0][0], scalar[1][1], scalar[2][2]); }

			/**
				Returns the euler angles of the orientation in vec3 representation.

				@return Returns the euler angles of the orientation in vec3 representation.
			*/
			const glm::vec3 get_euler_angles() const { return glm::eulerAngles(glm::tquat(rotation)); }

			/**
				Returns the roll of the orientation (in radians).

				@return Returns the roll of the Transform's orientation (in radians).
			*/
			const f32 get_roll_rad() const { return glm::roll(glm::tquat(rotation)); }

			/**
				Returns the yaw of the orientation (in radians).

				@return Returns the yaw of the Transform's orientation (in radians).
			*/
			const f32 get_yaw_rad() const { return glm::yaw(glm::tquat(rotation)); }

			/**
				Returns the pitch of the orientation (in radians).

				@return Returns the pitch of the Transform's orientation (in radians).
			*/
			const f32 get_pitch_rad() const { return glm::pitch(glm::tquat(rotation)); }

			/**
				Returns the roll of the orientation (in degrees).

				@return Returns the roll of the Transform's orientation (in degrees).
			*/
			const f32 get_roll_deg() const { return glm::degrees(glm::roll(glm::tquat(rotation))); }

			/**
				Returns the yaw of the orientation (in degrees).

				@return Returns the yaw of the Transform's orientation (in degrees).
			*/
			const f32 get_yaw_deg() const { return glm::degrees(glm::yaw(glm::tquat(rotation))); }

			/**
				Returns the pitch of the orientation (in degrees).

				@return Returns the pitch of the Transform's orientation (in degrees).
			*/
			const f32 get_pitch_deg() const { return glm::degrees(glm::pitch(glm::tquat(rotation))); }

			/**
				Returns the transform's forward vector.

				@return Returns the transform's forward vector.
			*/
			const glm::vec3 get_forward() const;

			/**
				Returns the transform's right vector.

				@return Returns the transform's right vector.
			*/
			const glm::vec3 get_right() const;

			/**
				Returns the transform's up vector.

				@return Returns the transform's up vector.
			*/
			const glm::vec3 get_up() const;
			
			/**
				Returns the TRS(Translation * Rotation * Scalar) matrix.

				@return Returns the TRS Column-Major matrix. Can be used for passing to a shader.
			*/
			const glm::mat4 get_matrix() const { return translation * rotation * scalar; }

		private:
			/// Matrix(Column-Major) representation of the location in local space
			glm::mat4 translation;
			/// Matrix(Column-Major) representation of the orientation
			glm::mat4 rotation;
			/// Matrix(Column-Major) representation of the scale
			glm::mat4 scalar;

	
	};
}

