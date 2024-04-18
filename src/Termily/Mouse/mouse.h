#pragma once

#include "../Utill/type.h"
#include <stdbool.h>
#include <windows.h>

extern u16 mouse_err;

typedef struct Mouse {
	u32 key, x, y;
	bool press, made;
} mouse_t;

extern mouse_t mouse_left;
extern mouse_t mouse_right;

u32
getMouseX();

u32
getMouseY();

bool
checkMouseDown(mouse_t *mouse);

bool
checkMousePress(mouse_t *mouse);
