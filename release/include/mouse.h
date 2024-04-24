#pragma once

#include "type.h"
#include <windows.h>

extern u16 mouse_err;

typedef struct Mouse {
	u32 key, x, y;
	bool press, made;
} mouse_t;

extern mouse_t mouse_left;
extern mouse_t mouse_right;

u32
mouse_getMouseX();

u32
mouse_getMouseY();

bool
mouse_checkMouseDown(mouse_t *mouse);

bool
mouse_checkMousePress(mouse_t *mouse);
