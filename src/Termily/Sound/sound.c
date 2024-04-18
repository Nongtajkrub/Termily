#include "sound.h"
#include "sound_err.h"
#include "../Utill/macro.h"
#include <stdbool.h>
#include <windows.h>

u16 sound_err = SUCCESS;

void
makeSound(sound_t *sound, LPCSTR path) {
	sound->path = path;
	sound->made = true;
}

void
playSound(sound_t *sound) {
	if (!sound->made) {
		soundNotMade(PLAY_SOUND_FUNC);
		return;
	}
	if (!PlaySound(sound->path, NULL, SND_FILENAME | SND_ASYNC)) {
		soundNotPlay(PLAY_SOUND_FUNC);	
	}
} 
