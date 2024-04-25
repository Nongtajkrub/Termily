#pragma once

#include "../Utill/type.h"

extern u16 save_err;

void
saveData(const char* DATA_NAME, void* data, data_type_t type);
