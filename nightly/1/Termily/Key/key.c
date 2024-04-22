#include "key.h"
#include "key_err.h"
#include "key_macro.h"
#include "../Utill/macro.h"
#include <windows.h>

u16 key_err = SUCCESS;

key_t key_up = {
	.key = VK_UP,
	.press = false,
	.made = true
};
key_t key_down = {
	.key = VK_DOWN,
	.press = false,
	.made = true
};
key_t key_left = {
	.key = VK_LEFT,
	.press = false,
	.made = true
};
key_t key_right = {
	.key = VK_RIGHT,
	.press = false,
	.made = true
};

bool 
checkKeyDown(key_t *key) {
	if (!key->made) {
		keyNotMade(CHECK_KEY_DOWN_FUNC);
		return false;
	}
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
	if (!key->made) {
		keyNotMade(CHECK_KEY_PRESS_FUNC);
		return false;
	}
	if (GetAsyncKeyState(key->key) & 0x8000) {
		return true;
	}
	return false;
}
