#pragma once

#include "type.h"
#include "graphic.h"
#include "actor.h"
#include "key.h"
#include "mouse.h"
#include "sound.h"
#include "text.h"

typedef struct Termily {
	bool should_run;
	u32 key_to_exit;
	int version[3];
} termily_t;

void
initTermily(termily_t *termily, u32 key_to_exit);

void
termilyExit(termily_t *termily); 
