#pragma once

#include "key.h"
#include "../Share/macro.h"
#include <stdio.h>

static inline void
keyNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];
 
	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> key struct not made", FUNC);
	perror(err_mess);
}
