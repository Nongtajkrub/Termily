#include "graphic.h"
#include "graphic_macro.h"
#include "graphic_err.h"
#include "../Utill/macro.h"
#include <stdio.h>
#include <stdbool.h>

u16 graph_err = SUCCESS;

static u8
makeScreen(char screen_buff[MAX_H][MAX_W], graph_t *graph) {
	if (graph->w > MAX_W) return EXCEED_MAX_W;
	if (graph->h > MAX_H) return EXCEED_MAX_H;

	for (u32 h = 0; h < graph->h; h++) {
		for (u32 w = 0; w < graph->w; w++) {
			if (h == 0 || w == 0 || h == graph->h - 1 || w == graph->w - 1) {
				screen_buff[h][w] = SCREEN_BOARDER;
			} else {
				screen_buff[h][w] = SCREEN_BACKGROUND;
			}
		}
	}

	return SUCCESS;
}

void
makeGraph(graph_t *graph, u32 w, u32 h) {
	u8 r;

	if (r == EXCEED_MAX_H) {
		exceedMaxH(MAKE_GRAPH_FUNC, graph);
		return;
	}
	if (r == EXCEED_MAX_W) {
		exceedMaxW(MAKE_GRAPH_FUNC, graph);
		return;
	}

	graph->w = w;
	graph->h = h;
	graph->made = true;
	r = makeScreen(graph->win, graph);
}

void
drawGraphic(graph_t *graph) {
	if (!graph->made) {
		graphNotMade(DRAW_GRAPH_FUNC);
		return;
	}

	printf("\033[2J\033[1;1H");
	for (u32 h = 0; h < graph->h; h++) {
		printf("%s", graph->win[h]);
		printf("\n");
	}	
}

void
clearScreen(graph_t *graph) {
	for (u32 h = 0; h < graph->h; h++) {
		for (u32 w = 0; w < graph->w; w++) {
			if (
				graph->win[h][w] == SCREEN_BOARDER ||
				graph->win[h][w] == SCREEN_BACKGROUND
				) continue;
			graph->win[h][w] = SCREEN_BACKGROUND;
		}
	}
}

void 
drawText(graph_t *graph, const char* TEXT, u32 x, u32 y) {
	u32 text_ind;	

	if (x > graph->w || y > graph->h) return; 
	text_ind = 0;
	for (u32 h = y; h < graph->h; h++) {
		for (u32 w = x; w < graph->w; w++) {
			if (graph->win[h][w] == SCREEN_BOARDER) continue;
			if (TEXT[text_ind] == '\0')	return;;
			graph->win[h][w] = TEXT[text_ind];
			text_ind++;
		}
	}	
}
