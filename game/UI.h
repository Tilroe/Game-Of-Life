#pragma once

#include "raylib.h"

class UI
{
public:
	virtual void draw() const = 0;
	inline bool check_mouse_collision(Vector2 mouse_position) const
	{
		return CheckCollisionPointRec(mouse_position, screen_position);
	}
protected:
	Rectangle screen_position{};
};

