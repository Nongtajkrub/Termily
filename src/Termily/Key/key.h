#pragma once

#include "../Utill/type.h"
#include <windows.h>

extern u16 key_err;

typedef struct Key {
	u32 key;
	bool press,
		 made;
} key_t;

extern key_t key_up;
extern key_t key_down;
extern key_t key_right;
extern key_t key_left;

bool 
checkKeyDown(key_t *key);

bool
checkKeyPress(key_t *key);
