#include "actor.h"
#include "actor_err.h"
#include "../termily.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"
#include <process.h>

u16 actor_err = SUCCESS;

// Use in function below
static void
keepActorInWin(void* arg) {
	actor_t *actor = (actor_t*)arg;

	while (should_run) {
		if (actor->x >= GET_BOADER_RIGHT(actor->graph->w)) {
			actor->x = GET_BOADER_RIGHT(actor->graph->w) - 1;
		}
		if (actor->y >= GET_BOADER_BOTTOM(actor->graph->h)) {
			actor->y = GET_BOADER_BOTTOM(actor->graph->h) - 1;
		}
		if (actor->x <= GET_BOADER_LEFT) {
			actor->x = 2;
		}
		if (actor->y <= GET_BOADER_TOP) {
			actor->y = 1;
		}
	}

	_endthread();
}

void
makeActor(actor_t *actor, graph_t *graph, char charac, bool in_win) {
	actor->x = 0;
	actor->y = 0;
	actor->charac = charac;
	actor->graph = graph;
	actor->in_win = in_win;
	actor->made = true;

	if (in_win) {
		_beginthread(keepActorInWin, 0, actor);
	}
}

void
setPos(actor_t *actor, i32 x, i32 y) {
	if (!actor->made) {
		actorNotMade(SET_POS_FUNC);
		return;
	}
	actor->x = x;
	actor->y = y;
}

void
drawActor(actor_t *actor) {
	if (!actor->made) {
		actorNotMade(DRAW_ACTOR_FUNC);
		return;
	}
	if (
		actor->x >= actor->graph->w - 1 ||
		actor->y >= actor->graph->h - 1 ||
		actor->x <= 0 || 
		actor->y <= 0 
		) {
		return;
	}
	actor->graph->win[actor->y][actor->x] = actor->charac;
}

bool
checkCollide(actor_t *actor1, actor_t *actor2) {
	if (!actor1->made || !actor2->made) {
		actorNotMade(CHECK_COLLIDE_FUNC);
		return false;
	}
	if (actor1->x == actor2->x && actor1->y == actor2->y) {
		return true;
	}
	return false;
}
