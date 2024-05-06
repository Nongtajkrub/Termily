#include "../Utill/macro.h"
#include "clock.h"
#include "clock_err.h"
#include "clock_macro.h"
#include <process.h>

u16 clock_err = SUCCESS;

// Use as an argument for the function waitThread
typedef struct WaitThreadArg {
	term_clock_t *clock;
	termily_t *termily;
} wait_thr_arg_t;

void 
clock_make(term_clock_t *clock, f32 *time, f32 wait, void (*func)()) {
	clock->wait = wait;
	clock->func = func;
	clock->time = time;
	clock->prev_time = (*time);
	clock->should_wait = true;
	clock->made = true;
}

static inline void
wait(term_clock_t* clock) {
	f32 delta_time;

	delta_time = (*clock->time) - clock->prev_time;
	if (delta_time >= clock->wait) {
		clock->prev_time = (*clock->time);
		clock->func();
	}
}

void
clock_wait(term_clock_t *clock) {	
	if (!clock->made) {
		clokcNotMade(WAIT_FUNC);
		return;
	}

	wait(clock);
}

static void
waitThread(void* arg) {
	wait_thr_arg_t *wait_thr = (wait_thr_arg_t*)arg;

	while (wait_thr->clock->should_wait && wait_thr->termily->should_run) {
		wait(wait_thr->clock);
	}

	_endthread();
}

void clock_waitThread(term_clock_t *clock, termily_t *termily) {
	if (!clock->made) {
		clokcNotMade(WAIT_THREAD_FUNC);
		return;
	}

	wait_thr_arg_t wait_thr = {
		.clock = clock,
		.termily = termily
	};

	_beginthread(waitThread, 0, &wait_thr);	
}

void 
clock_stopWaitThread(term_clock_t *clock) {
	clock->should_wait = false;
}
