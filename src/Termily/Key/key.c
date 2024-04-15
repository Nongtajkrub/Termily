#include "key.h"
#include <winuser.h>

key_t key_up = {
	.key = VK_UP,
	.press = false
};
key_t key_down = {
	.key = VK_DOWN,
	.press = false
};
key_t key_left = {
	.key = VK_LEFT,
	.press = false
};
key_t key_right = {
	.key = VK_RIGHT,
	.press = false
};

bool 
checkKeyDown(key_t *key) {
	if (GetAsyncKeyState(key->key) & 0x8000 && !key->press) {
		key->press = true;
		return true;
	}
	if (!GetAsyncKeyState(key->key)) {
		key->press = false;
	}
	return false;
}

bool
checkKeyPress(key_t *key) {
	if (GetAsyncKeyState(key->key) & 0x8000) {
		return true;
	}
	return false;
}
