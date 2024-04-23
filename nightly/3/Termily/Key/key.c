#include "key.h"
#include "key_err.h"
#include "key_macro.h"
#include "../Utill/macro.h"
#include <windows.h>

u16 key_err = SUCCESS;

key_t key_A = {
	.key = 0x41,
	.press = false,
	.made = true,
};
key_t key_B = {
	.key = 0x42,
	.press = false,
	.made = true,
};
key_t key_C = {
	.key = 0x43,
	.press = false,
	.made = true,
};
key_t key_D = {
	.key = 0x44,
	.press = false,
	.made = true,
};
key_t key_E = {
	.key = 0x45,
	.press = false,
	.made = true,
};
key_t key_F = {
	.key = 0x46,
	.press = false,
	.made = true,
};
key_t key_G = {
	.key = 0x47,
	.press = false,
	.made = true,
};
key_t key_H = {
	.key = 0x48,
	.press = false,
	.made = true,
};
key_t key_I = {
	.key = 0x49,
	.press = false,
	.made = true,
};
key_t key_J = {
	.key = 0x4A,
	.press = false,
	.made = true,
};
key_t key_K = {
	.key = 0x4B,
	.press = false,
	.made = true,
};
key_t key_L = {
	.key = 0x4C,
	.press = false,
	.made = true,
};
key_t key_M = {
	.key = 0x4D,
	.press = false,
	.made = true,
};
key_t key_N = {
	.key = 0x4E,
	.press = false,
	.made = true,
};
key_t key_O = {
	.key = 0x4F,
	.press = false,
	.made = true,
};
key_t key_P = {
	.key = 0x50,
	.press = false,
	.made = true,
};
key_t key_Q = {
	.key = 0x51,
	.press = false,
	.made = true,
};
key_t key_R = {
	.key = 0x52,
	.press = false,
	.made = true,
};
key_t key_S = {
	.key = 0x53,
	.press = false,
	.made = true,
};
key_t key_T = {
	.key = 0x54,
	.press = false,
	.made = true,
};
key_t key_U = {
	.key = 0x55,
	.press = false,
	.made = true,
};
key_t key_V = {
	.key = 0x56,
	.press = false,
	.made = true,
};
key_t key_W = {
	.key = 0x57,
	.press = false,
	.made = true,
};
key_t key_X = {
	.key = 0x58,
	.press = false,
	.made = true,
};
key_t key_Y = {
	.key = 0x59,
	.press = false,
	.made = true,
};
key_t key_Z = {
	.key = 0x5A,
	.press = false,
	.made = true,
};
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
key_checkKeyDown(key_t *key) {
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
key_checkKeyPress(key_t *key) {
	if (!key->made) {
		keyNotMade(CHECK_KEY_PRESS_FUNC);
		return false;
	}
	if (GetAsyncKeyState(key->key) & 0x8000) {
		return true;
	}
	return false;
}
