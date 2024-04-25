#pragma once

#include "text.h"
#include "text_macro.h"
#include "../Utill/type.h"
#include "../Utill/macro.h"
#include <stdio.h>

static inline void
textNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> text struct not made", FUNC);
	perror(err_mess);
	text_err = TEXT_NOT_MADE;
}

static inline void
textToLong(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> text to long", FUNC);
	perror(err_mess);
	text_err = TEXT_TO_LONG;
}

static inline void
exceedTextSpace(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> exceed text limit");
	perror(err_mess);
	text_err = EXCEED_TEXT_SPACING; 
}
