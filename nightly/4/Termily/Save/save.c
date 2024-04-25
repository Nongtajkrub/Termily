#include "save.h"
#include "save_err.h"
#include "save_macro.h"
#include "../Utill/macro.h"
#include <stdio.h>

u16 save_err = SUCCESS;

void
saveData(const char* DATA_NAME, void* data, data_type_t type) {
	FILE *fptr;

	fopen_s(&fptr, SAVE_FILE, "a");
	if (fptr == NULL) {
		failToOpenFile(SAVE_DATA_FUNC);
		return;
	}

	switch (type) {
		case TYPE_INT:
			int data_int = *(int*)data;
			fprintf(
				fptr,
				"%s %d %c e\n",
				DATA_NAME,
				data_int,
				INT_TYPE_INDICATOR
				);
			break;
		case TYPE_CHAR:
			char* data_ch = (char*)data;
			fprintf(
				fptr,
				"%s \"%s\" %c e\n",
				DATA_NAME, data_ch,
				CHAR_TYPE_INDICATOR
				);
			break;
		case TYPE_STR:
			char* data_str = (char*)data;
			fprintf(
				fptr,
				"%s \"%s\" %c e\n",
				DATA_NAME,
				data_str,
				STR_TYPE_INDICATOR
				);
			break;
	}

	fclose(fptr);
}
