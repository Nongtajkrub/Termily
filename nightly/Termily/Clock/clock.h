#pragma once

#include "../Utill/type.h"
#include "../termily_type.h"

extern u16 clock_err;

typedef struct TermilyClock {
	void (*func)();
	f32 wait,
		*time,
		prev_time;
	bool should_wait,
		 made;
} term_clock_t;

void
clock_make(term_clock_t *clock, f32 *time, f32 wait, void (*func)());

void
clock_wait(term_clock_t *clock);

void
clock_waitThread(term_clock_t *clock, termily_t *termily);

void 
clock_stopWaitThread(term_clock_t *clock);
