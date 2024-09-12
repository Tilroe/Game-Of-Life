#include "game.h"

#include <cmath>
#include "raymath.h"
#include "SparseMatrix.h"


Game::Game(const int width, const int height) :
	width(width),
	height(height)
{

	kernels.push_back(new SparseMatrix(width, height));
	current_kernel = kernels[0];
}

Game::~Game()
{
	for (Kernel* k : kernels) {
		delete k;
	}
}

void Game::update(float dt)
{
	handle_camera();

	// Kernel updates
	if (state == PLAY) {
		time += dt;
		if (time > update_time) {
			time = std::fmod(time, update_time);
			current_kernel->update();
		}
	}
	
}

// Camera helper function forward declarations
void handle_movement(Camera2D& camera); 
void target_on_mouse(Camera2D& camera);  
void handle_zoom(Camera2D& camera);      
void camera_bounds_correction(Camera2D& camera, Vector2 bounds);  

void Game::handle_camera()
{
	target_on_mouse(camera);
	handle_movement(camera);
	handle_zoom(camera);
	camera_bounds_correction(camera, get_bounds());
}

// --- Camera helper functions ---
static void handle_movement(Camera2D& camera)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 mouse_delta = Vector2Scale(GetMouseDelta(), -1 / camera.zoom);
		camera.target = Vector2Add(camera.target, mouse_delta);
	}
}

static void target_on_mouse(Camera2D& camera)
{
	Vector2 mouse_world_pos = GetScreenToWorld2D(GetMousePosition(), camera);
	camera.offset = GetMousePosition();
	camera.target = mouse_world_pos;
}

static void handle_zoom(Camera2D& camera)
{
	float wheel = GetMouseWheelMove();
	if (wheel) {
		float scale_factor = 1.0f + (0.25f * fabsf(wheel));
		if (wheel < 0) scale_factor = 1.0f / scale_factor;
		camera.zoom = Clamp(camera.zoom * scale_factor, 0.125f, 64.0f);
	}
}

static void camera_bounds_correction(Camera2D& camera, Vector2 bounds)
{
	camera.target = Vector2Clamp(camera.target, Vector2{}, bounds);
}
// ------------------------------

void Game::draw() const
{
	Vector2 bounds = get_bounds();
	BeginMode2D(camera);

	current_kernel->draw();

	// Draw bounds
	DrawLineEx(Vector2{ 0, 0 }, Vector2{ bounds.x }, 20.f, GRAY);
	DrawLineEx(Vector2{ bounds.x, 0 }, Vector2{ bounds.x, bounds.y }, 20.f, GRAY);
	DrawLineEx(bounds, Vector2{ 0, bounds.y }, 10.f, GRAY);
	DrawLineEx(Vector2{ 0, bounds.y }, Vector2{ 0, 0 }, 20.f, GRAY);

	EndMode2D();
}
