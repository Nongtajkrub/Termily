#include "graphic.h"
#include "graphic_macro.h"
#include "graphic_err.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"
#include <stdio.h>
#include <windows.h>

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
graph_makeGraph(graph_t *graph, u16 w, u16 h) {
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
	graph->color[0] = '\0';
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
graph_drawPoint(graph_t *graph, char draw, u16 x, u16 y) {
	if (!graph->made) {
		graphNotMade(DRAW_POINT_FUNC);
		return;
	}

	if (
		x >= GET_BOADER_RIGHT(graph->w) ||
		x == GET_BOADER_LEFT ||
		y >= GET_BOADER_BOTTOM(graph->h) ||
		y == GET_BOADER_TOP
		) {
		return;
	}
	graph->win[y][x] = draw;
}

void
graph_drawLine(graph_t *graph, char look, u16 x1, u16 y1, u16 x2, u16 y2) {
	if (!graph->made) {
		graphNotMade(DRAW_LINE_FUNC);
		return;
	}

	f32 y,
		m; 
	i16	dis_x, dis_y;
	f32 step;

	dis_x = x2 - x1;
	dis_y = y2 - y1;
	m =  (f32)dis_y / (f32)dis_x;

	if (isinf(m)) {
		if (dis_y > 0) {
			for (u16 y = y1; y < y2; y++) {
				graph_drawPoint(graph, look, x1, y);
			}
			return;
		}
		if (dis_y < 0) {
			for (u16 y = y1; y > y2; y--) {
				graph_drawPoint(graph, look, x1, y);
			}
			return;
		}
	}

	if (fabs(m) < STEEP_LINE) {
		step = LINE_STEP_MAX;
	} else if (fabs(m) > STEEP_LINE && fabs(m) < GRADUAL_LINE) {
		step = LINE_STEP_MED;
	} else {
		step = LINE_STEP_MIN;
	}
	
	if (dis_x >= 0) {
		for (f32 x = x1; x < x2; x += step) {
			y = (f32)((m * (x - x1)) + y1);
			graph_drawPoint(graph, look, (u16)round(x), (u16)round(y));
		}
		return;
	}
	if (dis_x <= 0) {
		for (f32 x = x1; x > x2; x -= step) {
			y = (m * ((f32)x - (f32)x1)) + (f32)y1;
			graph_drawPoint(graph, look, (u16)round(x), (u16)round(y));
		}
		return;
	}
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
