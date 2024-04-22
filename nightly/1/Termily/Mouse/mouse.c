#include "mouse.h"
#include "mouse_err.h"
#include "mouse_macro.h"
#include "../Utill/type.h"
#include <windows.h>

u16 mouse_err = SUCCESS;

mouse_t mouse_left = {
	.key = VK_LBUTTON,
	.press = false,
	.made = true
};

mouse_t mouse_right = {
	.key = VK_RBUTTON,
	.press = false,
	.made = true
};

u32
getMouseX() {
	static POINT mouse_pos;

	GetCursorPos(&mouse_pos);
	return mouse_pos.x;
}

u32
getMouseY() {
	static POINT mouse_pos;

	GetCursorPos(&mouse_pos);
	return mouse_pos.y;
}

bool 
checkMouseDown(mouse_t *mouse) {
	if (!mouse->made) {
		mouseNotMade(CHECK_MOUSE_DOWN_FUNC);
		return false;
	}
	if (GetAsyncKeyState(mouse->key) & 0x8000 && !mouse->press) {
		mouse->press = true;
		mouse->x = getMouseX();
		mouse->y = getMouseY();
		return true;
	}
	if (!GetAsyncKeyState(mouse->key)) {
		mouse->press = false;
	}
	return false;
}

bool
checkMousePress(mouse_t *mouse) {
	if (!mouse->made) {
		mouseNotMade(CHECK_MOUSE_PRESS_FUNC);
		return false;
	}
	if (GetAsyncKeyState(mouse->key) & 0x8000) {
		mouse->press = true;
		mouse->x = getMouseX();
		mouse->y = getMouseY();
		return true;
	}
	return false;
}
