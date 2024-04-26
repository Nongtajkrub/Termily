#pragma once

#include "../Utill/type.h"

#define MAX_W 480
#define MAX_H 270
#define COLOR_SIZE 64

extern u16 graph_err;

typedef struct Graphic {
	u32 w,h;
	char win[MAX_H][MAX_W],
		 color[COLOR_SIZE];
	bool made;
} graph_t;

void
graph_makeGraph(graph_t *graph, u32 w, u32 h);

void
graph_setColor(graph_t *graph, const char* COLOR); 

void
graph_drawLine(graph_t *graph, u32 x1, u32 y1, u32 x2, u32 y2);

void
graph_drawGraphic(graph_t *graph);

void
graph_clearScreen(graph_t *graph);
