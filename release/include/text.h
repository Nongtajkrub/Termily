#pragma once

#include "graphic.h"
#include "type.h"

#define TEXT_SIZE 64

extern u16 text_err;

typedef enum TextProb {
	UNDER_LINE = 1,
	SPACE_SAME_SPACING = 2,
	NONE = 4
} text_prob_t;

typedef struct Text {
	char text[TEXT_SIZE];
	text_prob_t prob;
	u16 space_x, space_y;
	graph_t *graph;
	bool wrap, made;
} text_t;

void
makeText(
	text_t *text,
	const char TEXT[TEXT_SIZE],
	text_prob_t prob,
	graph_t *graph
	);

void
text_changeText(text_t *text, const char* NEW_TEXT);

void
text_changeSpacingX(text_t *text, u8 new_space);

void
text_changeSpacingY(text_t *text, u8 new_space);

void
text_setWrap(text_t *text, bool value);

void
text_drawText(text_t *text, u32 x, u32 y);
