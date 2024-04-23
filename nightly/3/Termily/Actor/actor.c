#include "actor.h"
#include "actor_err.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"
#include <process.h>

u16 actor_err = SUCCESS;

void
actor_keepActorInWin(actor_t *actor) {
	if (actor->x >= GET_BOADER_RIGHT(actor->graph->w)) {
		actor->x = GET_BOADER_RIGHT(actor->graph->w) - 1;
	}
	if (actor->y >= GET_BOADER_BOTTOM(actor->graph->h)) {
		actor->y = GET_BOADER_BOTTOM(actor->graph->h) - 1;
	}
	if (actor->x <= GET_BOADER_LEFT) {
		actor->x = GET_BOADER_LEFT + 1;
	}
	if (actor->y <= GET_BOADER_TOP) {
		actor->y = GET_BOADER_TOP + 1;
	}
}

void
actor_makeActor(actor_t *actor, graph_t *graph, char charac) {
	actor->x = 0;
	actor->y = 0;
	actor->charac = charac;
	actor->graph = graph;
	actor->made = true;
}

void
actor_setPos(actor_t *actor, i32 x, i32 y) {
	if (!actor->made) {
		actorNotMade(SET_POS_FUNC);
		return;
	}
	actor->x = x;
	actor->y = y;
}

void
actor_drawActor(actor_t *actor) {
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
actor_checkCollide(actor_t *actor1, actor_t *actor2) {
	if (!actor1->made || !actor2->made) {
		actorNotMade(CHECK_COLLIDE_FUNC);
		return false;
	}
	if (actor1->x == actor2->x && actor1->y == actor2->y) {
		return true;
	}
	return false;
}
