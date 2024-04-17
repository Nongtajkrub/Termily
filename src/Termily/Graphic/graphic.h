#pragma once

#include <stdbool.h>
#include "../Utill/type.h"

#define MAX_W 480
#define MAX_H 270

extern u16 graph_err;

typedef struct Graphic {
	u32 w, h;
	char win[MAX_H][MAX_W];
	bool made;
} graph_t;

void
makeGraph(graph_t *graph, u32 w, u32 h);

void
drawGraphic(graph_t *graph);

void
clearScreen(graph_t *graph);

void
drawText(graph_t *graph, const char* const TEXT, u32 x, u32 y);
