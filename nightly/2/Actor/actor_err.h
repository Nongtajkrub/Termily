#pragma once

#include "actor.h"
#include "actor_macro.h"
#include "../Utill/macro.h"
#include <stdio.h>

static inline void
actorNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> actor struct  not made", FUNC);
	perror(err_mess);
	actor_err = ACTOR_NOT_MADE;
}
