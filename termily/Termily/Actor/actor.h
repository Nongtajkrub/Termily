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
makeActor(actor_t *actor, graph_t *graph, char charac);

void
setPos(actor_t *actor, i32 x, i32 y);

void
drawActor(actor_t *actor);

bool
checkCollide(actor_t *actor1, actor_t *actor2);
