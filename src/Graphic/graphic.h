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
graph_makeGraph(graph_t *graph, u16 w, u16 h); 

void
graph_setColor(graph_t *graph, const char* COLOR); 

void
graph_drawPoint(graph_t *graph, char draw, u16 x, u16 y); 

void
graph_drawLine(graph_t *graph, char look, u16 x1, u16 y1, u16 x2, u16 y2); 

void
graph_drawGraphic(graph_t *graph);

void
graph_clearScreen(graph_t *graph);
