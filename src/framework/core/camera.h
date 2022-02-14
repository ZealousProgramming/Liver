#pragma once

#include "common.h"
#include "../../core/math/math.h"

namespace Liver {
	/**
		Implementation of a Virtual Camera.
	*/
	class Camera {
		public:
			/**
				Used to describe the type of project the camera should use.
			*/
			enum class ProjectionType {
				/// Depth is preserved in the final render.
				/// Resulting in everything having the proper
				/// distance and depth from one another. 
				PERSPECTIVE = 1,
				/// Depth is NOT preserved in the final render.
				/// Resulting in everything seemly having the same 
				/// distance from one another.
				ORTHO = 2
			};
		public:
			Camera();
			~Camera() = default;
			
			/** 
				Sets the camera to be flagged as the current camera in use.
			*/
			void make_current();
			
			/**
				Removes the camera from being the current in use.
			*/
			void not_current();

			/**
				Changes the camera type, and how the final render will look.

				@param new_type The desired CameraType.
			*/
			void set_projection_type(const ProjectionType new_type) { projection_type = new_type; }


			/**
				Changes the camera's perspective projection matrix with the desired settings.

				@param fov_deg Field of View (in degrees)
				@param aspect_ratio The aspect_ratio of the window
				@param near_plane The near clipping plane distance
				@param far_plane The far clipping plane distance
			*/
			void set_projection_perspective(const f32 fov_deg, const f32 aspect_ratio, const f32 near_plane, const f32 far_plane);

			/**
				Changes the camera's orthographic projection matrix with the desired settings.

				@param left 
				@param right 
				@param bottom 
				@param top 
			*/
			void set_projection_orthographic(const f32 left, const f32 right, const f32 bottom, const f32 top);
			
			/**
				Changes the camera's orthographic projection matrix with the desired settings.

				@param left 
				@param right 
				@param bottom 
				@param top 
			*/
			void set_projection(const glm::vec2 window_size);



			void set_transform(const Transform& new_transform);

			/**
				Returns the unique camera ID.
				
				@return Returns the unique camera ID.
			*/
			const u16 get_id() const { return id; }

			/**
				Returns the near clipping plane.

				@return Returns the near clipping plane.
			*/
			const f32 get_near() const { return near_plane; }

			/**
				Returns the far clipping plane.

				@return Returns the far clipping plane.
			*/
			const f32 get_far() const { return far_plane;  }

			const Transform get_transform() const { return transform; }
			Transform& get_mut_transform() { return transform; }

			/**
				Returns the current projection type.

				@return Returns the current projection type.
			*/
			const ProjectionType get_projection_type() const { return projection_type; }
			
			/**
				Returns the camera's projection matrix

				@return Returns the current projection matrix.
			*/
			const glm::mat4 get_projection() const { return projection; }

			/**
				The current camera in use for rendering.
			*/
			static Camera* current_camera;
		private:
			// TODO(devon): Move the transform to a component or a GameObject type construct 
			// after implementing the components and scene system.
			Transform transform;

			/// Is this Camera the current camera in use?
			bool current;
			/// Unique Identifier to be able to identify specific cameras
			u16 id;
			/// The distance(lower bounds) from the camera to determine what should get rendered.
			f32 near_plane;
			/// The distance(upper bounds) from the camera to determine what should get rendered.
			f32 far_plane;
			/// The field of view (in degrees) of the camera.
			f32 fov;
			/// The aspect_ratio of the window
			f32 aspect_ratio;
			/// The type of projection the camera should use. @see ProjectionType
			ProjectionType projection_type;
			/// The camera's projection to be used in the projection * view * model render calculations.
			glm::mat4 projection;

			/// The number of cameras in the scene.
			static u8 camera_count;
	};
}