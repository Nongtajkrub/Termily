#include "termily.h"
#include <process.h>
#include <synchapi.h>

bool should_run = true;

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
	_beginthread(checkShouldRun, 0, NULL);
}

void
termilyExit() {
	should_run = false;
	Sleep(100);
}
