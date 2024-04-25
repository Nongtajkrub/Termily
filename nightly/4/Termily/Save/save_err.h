#pragma once

#include "save.h"
#include "save_macro.h"
#include "../Utill/macro.h"
#include <stdio.h>

static inline void
failToOpenFile(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> fail to open file", FUNC);
	perror(err_mess);
	save_err = FAIL_TO_OPEN_FILE;
}
