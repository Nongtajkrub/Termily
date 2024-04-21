#include "termily.h"
#include <process.h>

bool should_run = true;
HANDLE should_run_thr;

static void
checkShouldRun() {
	while (should_run) {
		if (
			graph_err != 0 ||
			actor_err != 0 ||
			key_err != 0||
			mouse_err != 0 ||
			sound_err != 0 ||
			text_err != 0
			) should_run = false;
	}
	
	_endthread();
}

void
initTermily() {
	should_run_thr = (HANDLE)_beginthread(checkShouldRun, 0, NULL);
}

void
termilyExit() {
	should_run = false;
	WaitForSingleObject(should_run_thr, 5000);
}
