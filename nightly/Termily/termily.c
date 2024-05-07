#include "termily.h"
#include "Utill/macro.h"
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <synchapi.h>

static void
checkShouldRun(void* arg) {
	termily_t *termily = (termily_t*)arg;

	while (termily->should_run) {
		if (
			graph_err != 0 ||
			actor_err != 0 ||
			key_err != 0||
			mouse_err != 0 ||
			sound_err != 0 ||
			text_err != 0 ||
			clock_err != 0 ||
			(GetAsyncKeyState(termily->key_to_exit)) & 0x8000
			) termilyExit(termily); 
	}
}

static void
startClock(void* arg) {
	termily_t *termily = (termily_t*)arg;
	LARGE_INTEGER start_time,
				  current_time,
				  freq;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start_time);
	
	while (termily->should_run) {
		QueryPerformanceCounter(&current_time);
		termily->time =
			(f32)(current_time.QuadPart - start_time.QuadPart)
			/ 1.0f
			/ freq.QuadPart;

	}

	_endthread();
}

void
initTermily(termily_t *termily, u32 key_to_exit) {
	termily->should_run = true;
	termily->key_to_exit = key_to_exit;
	MAKE_VERSION_ARRAY(termily->version);

	_beginthread(checkShouldRun, 0, termily);
	_beginthread(startClock, 0, termily);
}

void
mainLoop(termily_t *termily) {
	static bool first_call;
	static f32 prev_time;

	if (!first_call) {
		termily->delta_time = termily->time - prev_time;
		prev_time = termily->time;
	} else if (first_call) {
		prev_time = termily->time;
	}
}

void
termilyExit(termily_t *termily) {
	termily->should_run = false;
	Sleep(500);
}
