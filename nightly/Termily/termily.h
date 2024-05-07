#pragma once

#include "Utill/type.h"
#include "Graphic/graphic.h"
#include "Actor/actor.h"
#include "Key/key.h"
#include "Mouse/mouse.h"
#include "Sound/sound.h"
#include "Text/text.h"
#include "Clock/clock.h"
#include "termily_type.h"

void
initTermily(termily_t *termily, u32 key_to_exit);

void
mainLoop(termily_t *termily);

void
termilyExit(termily_t *termily);
