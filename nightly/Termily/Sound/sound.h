#pragma once

#include "../Utill/type.h"
#include <windows.h>

#define SOUND_PATH_SIZE 512

extern u16 sound_err;

typedef struct Sound {
	LPCSTR path;
	bool made;
} sound_t;

void
sound_makeSound(sound_t *sound, LPCSTR path);

void
sound_playSound(sound_t *sound); 
