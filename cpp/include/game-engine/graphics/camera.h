#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <game-engine/math/point.h>

namespace Engine { namespace Graphics {
	
	struct Camera
	{
		bool perspective;
		union {
			struct {
				float  v_fov;
				Point3 position;
				Point3 target;
				Point3 up;
			};
			struct {
				float left;
				float right;
				float top;
				float bottom;
			};
		};
		float near;
		float far;

		Camera(float,Point3,Point3,Point3,float,float);
		Camera(float,float,float,float,float,float);
	};

	extern const Camera DEFAULT_CAMERA;
}}

#endif
