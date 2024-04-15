#pragma once

#include "actor.h"
#include "actor_macro.h"
#include <stdio.h>

static inline void
actorNotMade() {
	perror("The actor struct is incomplete");
	actor_err = ACTOR_NOT_MADE;
}
