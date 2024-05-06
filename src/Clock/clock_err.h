#pragma once

#include "../Utill/type.h"
#include "../Utill/macro.h"
#include "clock.h"
#include "clock_macro.h"

static inline void
clokcNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf(err_mess, "%s -> clock struct not made", FUNC);
	perror(err_mess);
	clock_err = CLOCK_NOT_MADE;
}
