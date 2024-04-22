#pragma once

#include "graphic.h"
#include "graphic_macro.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"
#include <stdio.h>

static inline void
graphNotMade(const char* FUNC) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> graphic struct not made", FUNC);
	perror(err_mess);
	graph_err = GRAPH_NOT_MADE;
}

static inline void
exceedMaxH(const char* FUNC, graph_t *graph) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> height exceed limit", FUNC);
	perror(err_mess);
	graph->made = false;
	graph_err = EXCEED_MAX_H;
}

static inline void
exceedMaxW(const char* FUNC, graph_t *graph) {
	char err_mess[ERR_MESS_SIZE];

	sprintf_s(err_mess, ERR_MESS_SIZE, "%s -> width exceed limit", FUNC);
	perror(err_mess);
	graph->made = false;
	graph_err = EXCEED_MAX_W;
}
