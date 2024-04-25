#pragma once

#include "Utill/type.h"
#include "Graphic/graphic.h"
#include "Actor/actor.h"
#include "Key/key.h"
#include "Mouse/mouse.h"
#include "Sound/sound.h"
#include "Text/text.h"
#include "Save/save.h"

typedef struct Termily {
	bool should_run;
	u32 key_to_exit;
	int version[3];
} termily_t;

void
initTermily(termily_t *termily, u32 key_to_exit);

void
termilyExit(termily_t *termily); 
