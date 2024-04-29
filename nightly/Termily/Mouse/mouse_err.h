#pragma once

#include "../Utill/macro.h"
#include "mouse.h"
#include "mouse_macro.h"
#include <stdio.h>

static inline void
mouseNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> mouse struct not made", FUNC);
	perror(err_mess);
	mouse_err = MOUSE_NOT_MADE;
}
