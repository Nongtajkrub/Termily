#include "graphic.h"
#include "graphic_macro.h"
#include "graphic_err.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"

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
graph_makeGraph(graph_t *graph, u32 w, u32 h) {
	u8 r;

	graph->w = w;
	graph->h = h;
	r = makeScreen(graph->win, graph);
	if (r == EXCEED_MAX_H) {
		exceedMaxH(MAKE_GRAPH_FUNC);
		return;
	}
	if (r == EXCEED_MAX_W) {
		exceedMaxW(MAKE_GRAPH_FUNC);
		return;
	}
	graph->made = true;
}

void
graph_setColor(graph_t *graph, const char* COLOR) {
	if (!graph->made) {
		graphNotMade(SET_COLOR_FUNC);
		return;
	}
	if (sizeof(COLOR) > COLOR_SIZE) {
		exceedColorSize(MAKE_GRAPH_FUNC);
		return;
	}
	strcpy_s(graph->color, COLOR_SIZE, COLOR);
}

void
graph_drawGraphic(graph_t *graph) {
	if (!graph->made) {
		graphNotMade(DRAW_GRAPH_FUNC);
		return;
	}

	printf("\033[2J\033[1;1H");
	for (u32 h = 0; h < graph->h; h++) {
		printf("%s%s\033[0m", graph->color, graph->win[h]);
		printf("\n");
	}	
}

void
graph_clearScreen(graph_t *graph) {
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
