#pragma once

// Inint
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REVISION 3

#define MAKE_VERSION_ARRAY(ARRAY) do { \
    (ARRAY)[0] = (VERSION_MAJOR); \
    (ARRAY)[1] = (VERSION_MINOR); \
    (ARRAY)[2] = (VERSION_REVISION); \
} while(0)

// Error
#define ERR_MESS_SIZE 1024
#define SUCCESS 0

// Graphic
#define SCREEN_BOARDER '*'
#define SCREEN_BACKGROUND ' '

#define GET_BOADER_RIGHT(WIDTH) (WIDTH - 1)
#define GET_BOADER_BOTTOM(HEIGHT) (HEIGHT - 1)
#define GET_BOADER_LEFT 1
#define GET_BOADER_TOP 0
