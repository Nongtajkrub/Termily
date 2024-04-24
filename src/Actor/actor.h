#pragma once

#include "../Utill/type.h"
#include "../Graphic/graphic.h"

extern u16 actor_err;

typedef struct Actor {
	i32 x, y;
	char charac;
	graph_t *graph;
	bool made;
} actor_t;

void
actor_makeActor(actor_t *actor, graph_t *graph, char charac);

void
actor_setPos(actor_t *actor, i32 x, i32 y);

void
actor_keepActorInWin(actor_t *actor);

void
actor_drawActor(actor_t *actor);

bool
actor_checkCollide(actor_t *actor1, actor_t *actor2);
