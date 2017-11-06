
#ifndef LUXOFT_RACE_UTILS_H
#define LUXOFT_RACE_UTILS_H

#ifdef __linux__
  #include <sys/ioctl.h>
  #include <termios.h>
  #include <unistd.h>
  #include <cstring>
#elif _WIN32
  #include <windows.h>
  #include <conio.h>
#endif

#include "SSize.h"
#include "Keycodes.h"


namespace utils {

void consoleClear();
SSize getConsoleSize();
int getInputChar();

int rand(int min, int max);


}

#endif //LUXOFT_RACE_UTILS_H
