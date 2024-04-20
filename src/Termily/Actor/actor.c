#include "actor.h"
#include "actor_err.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"

u16 actor_err = SUCCESS;

void
makeActor(actor_t *actor, graph_t *graph, char charac) {
	actor->x = 0;
	actor->y = 0;
	actor->charac = charac;
	actor->graph = graph;
	actor->made = true;
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
		actor->x == actor->graph->w - 1 ||
		actor->y == actor->graph->h - 1 ||
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
