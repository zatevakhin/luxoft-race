
#ifndef LUXSOFTTASK_UTILS_H
#define LUXSOFTTASK_UTILS_H


#include <windows.h>

#include "Size.h"


namespace utils {


void consoleClear(HANDLE consoleHandle);
Size getConsoleSize(HANDLE consoleHandle);

int rand(int min, int max);


}

#endif //LUXSOFTTASK_UTILS_H
