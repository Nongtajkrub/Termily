#include "termily.h"
#include "Utill/macro.h"
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
			(GetAsyncKeyState(termily->key_to_exit)) & 0x8000
			) termilyExit(termily); 
	}
}

void
initTermily(termily_t *termily, u32 key_to_exit) {
	termily->should_run = true;
	termily->key_to_exit = key_to_exit;
	MAKE_VERSION_ARRAY(termily->version);

	_beginthread(checkShouldRun, 0, termily);
}

void
termilyExit(termily_t *termily) {
	termily->should_run = false;
	Sleep(500);
}
