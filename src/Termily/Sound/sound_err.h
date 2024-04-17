#pragma once

#include "sound.h"
#include "sound_macro.h"
#include "../Share/macro.h"
#include <stdio.h>

static inline void
soundNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> sound struct not made", FUNC);
	perror(err_mess);
	sound_err = SOUND_NOT_MADE;
}

static inline void
soundNotPlay(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s - sound could not be play", FUNC);
	perror(err_mess);
	sound_err = SOUND_NOT_PLAYED;
}
