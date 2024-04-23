#include "text.h"
#include "text_err.h"
#include "../Utill/macro.h"
#include "../Utill/type.h"

u16 text_err = SUCCESS;

void
makeText(
	text_t *text,
	const char TEXT[TEXT_SIZE],
	text_prob_t prob,
	graph_t *graph
	) {
	if (strlen(TEXT) > TEXT_SIZE) {
		textToLong(MAKE_TEXT_FUNC);
		return;
	}
	strcpy_s(text->text, TEXT_SIZE, TEXT);
	text->prob = prob;
	text->space_x = 0;
	text->space_y = 0;
	text->graph = graph;
	text->wrap = true;
	text->made = true;
}

void
changeText(text_t *text, const char* NEW_TEXT) {
	if (!text->made) {
		textNotMade(CHANGE_TEXT_FUNC);
		return;
	}
	if (strlen(NEW_TEXT) > TEXT_SIZE) {
		textToLong(CHANGE_TEXT_FUNC);
		return;
	}
	strcpy_s(text->text, TEXT_SIZE, NEW_TEXT);
}

// Use in two function below
static inline void
checkErrSpacing(text_t *text, u8 new_space) {
	if (!text->made) {
		textNotMade(CHANGE_SPACE_FUNC);
		return;
	}
	if (new_space > MAX_SPACING) {
		exceedTextSpace(CHANGE_SPACE_FUNC);
		return;
	}	
}

void
changeSpacingX(text_t *text, u8 new_space) {
	checkErrSpacing(text, new_space);	
	text->space_x = new_space;
}

void
changeSpacingY(text_t *text, u8 new_space) {
	checkErrSpacing(text, new_space);	
	text->space_y = new_space;
}

void
setWrap(text_t *text, bool value) {
	if (!text->made) {
		textNotMade(SET_WRAP_FUNC);
		return;
	}
	text->wrap = value;
}

// Use in the function below
static inline void
applyUnderline(text_t *text, u32 h, u32 w) {
	text->graph->win[h + 1][w] = '-';	
}

// Use in the function below
static void
applyProb(text_t *text, u32 h, u32 w) {
	if (text->prob == NONE) return;
	if (text->prob & UNDER_LINE) applyUnderline(text, h, w);
	/*
	if (SPACE_SAME_SPACING) {
	
	}
	*/
}

void 
drawText(text_t *text, u32 x, u32 y) {
	u32 text_ind;	

	if (!text->made) {
		textNotMade(DRAW_TEXT_FUNC);
		return;
	}

	if (x > text->graph->w || y > text->graph->h) return;
	text_ind = 0;
	for (u32 h = y; h < text->graph->h; h++) {
		for (u32 w = x; w < text->graph->w; w++) {
			if (text->graph->win[h][w] == SCREEN_BOARDER) {
				if (text->wrap) continue;
				return;
			}
			if (text->text[text_ind] == '\0') return;
			text->graph->win[h][w] = text->text[text_ind];
			applyProb(text, h, w);
			if (
				text->text[text_ind] != ' ' ||
				text->prob != SPACE_SAME_SPACING
				) w += text->space_x;
			text_ind++;
		}
		if (
			text->text[text_ind] != ' ' ||
			text->prob == SPACE_SAME_SPACING
			) h += text->space_y;
	}	
}
