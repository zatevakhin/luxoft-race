
#include "utils.h"


namespace utils {


void consoleClear( HANDLE consoleHandle )
{
  COORD coordScreen = { 0, 0 };
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  if(!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {
    return;
  }

  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  if(!FillConsoleOutputCharacter(consoleHandle,
     (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten)) {
    return;
  }

  if(!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {
    return;
  }

  if(!FillConsoleOutputAttribute(consoleHandle,
     csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten)) {
    return;
  }

  SetConsoleCursorPosition(consoleHandle, coordScreen);
}



Size getConsoleSize(HANDLE consoleHandle)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  GetConsoleScreenBufferInfo(consoleHandle, &csbi);

  std::size_t width  = csbi.srWindow.Right  - csbi.srWindow.Left;
  std::size_t height = csbi.srWindow.Bottom - csbi.srWindow.Top;

  return Size(width, height - 1);
}



int rand(int min, int max)
{
  return std::rand() % (max + 1 - min) + min;
}


}
