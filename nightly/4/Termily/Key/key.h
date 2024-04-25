#pragma once

#include "../Utill/type.h"
#include <windows.h>

extern u16 key_err;

typedef struct Key {
	u32 key;
	bool press,
		 made;
} key_t;

extern key_t key_A;
extern key_t key_B;
extern key_t key_C;
extern key_t key_D;
extern key_t key_E;
extern key_t key_F;
extern key_t key_G;
extern key_t key_H;
extern key_t key_I;
extern key_t key_J;
extern key_t key_K;
extern key_t key_L;
extern key_t key_M;
extern key_t key_N;
extern key_t key_O;
extern key_t key_P;
extern key_t key_Q;
extern key_t key_R;
extern key_t key_S;
extern key_t key_T;
extern key_t key_U;
extern key_t key_V;
extern key_t key_W;
extern key_t key_X;
extern key_t key_Y;
extern key_t key_Z;
extern key_t key_up;
extern key_t key_down;
extern key_t key_right;
extern key_t key_left;

void
key_makeKey(key_t *key, u32 checK_key);

bool 
key_checkKeyDown(key_t *key);

bool
key_checkKeyPress(key_t *key);
