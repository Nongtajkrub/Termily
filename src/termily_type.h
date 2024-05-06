// This file is here because when other file want to use the termily_t struct
// they can do so with out including any other un needed header.

#pragma once

#include "Utill/type.h"

typedef struct Termily {
	bool should_run;
	u32 key_to_exit;
	u8 version[3];
	f32 time,
		delta_time;
} termily_t;
