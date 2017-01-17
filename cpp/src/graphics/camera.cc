#include <game-engine/graphics/camera.h>

const Engine::Graphics::Camera Engine::Graphics::DEFAULT_CAMERA =
{ 110.0, { 8,0,15 }, { 8,8,0 }, { 0,0,1 }, 1.0, 10000.0 };

Engine::Graphics::Camera::Camera(float fov, Point3 p, Point3 t,
	Point3 u, float near, float far) :
perspective(true), v_fov(fov), position(p), target(t), up(u),
near(near), far(far)
{ }

Engine::Graphics::Camera::Camera(float l, float r, float t,	float b,
	float near, float far) :
perspective(false), left(l), right(r), top(t), bottom(b),
near(near), far(far)
{ }
