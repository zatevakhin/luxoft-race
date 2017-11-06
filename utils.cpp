
#include "utils.h"


namespace utils {


void consoleClear()
{
#ifdef __linux__
  std::cout << "\033c";
#elif _WIN32
  COORD coordScreen = { 0, 0 };
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

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
#endif
}



SSize getConsoleSize()
{
  std::size_t width;
  std::size_t height;

#ifdef __linux__
  struct winsize terminalWindow;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalWindow);
  width = static_cast<std::size_t>(terminalWindow.ws_col);
  height = static_cast<std::size_t>(terminalWindow.ws_row - 2);
#elif _WIN32
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  width = static_cast<std::size_t>(csbi.srWindow.Right  - csbi.srWindow.Left);
  height = static_cast<std::size_t>(csbi.srWindow.Bottom - csbi.srWindow.Top);
#endif

  return SSize(width, height - 1);
}



int rand(int min, int max)
{
  return std::rand() % (max + 1 - min) + min;
}



int getInputChar()
{
  int c;

  // Because in Linux not exists function getch()
  // I've made this "crutch".
#ifdef __linux__
  struct termios termios_old, termios_new;
  tcgetattr(STDIN_FILENO, &termios_old);

  termios_new = termios_old;

  termios_new.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_new);

  c = getchar();

  // Handling Linux terminal escape siquence
  if (c == KEY_ESCAPE) {
    struct termios original_ts, nowait_ts;

    tcgetattr(STDIN_FILENO, &original_ts);
    nowait_ts = original_ts;
    nowait_ts.c_lflag &= ~ISIG;
    nowait_ts.c_cc[VMIN]  = 0;
    nowait_ts.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &nowait_ts);

    if((c = getchar()) != EOF) {
      if (c == ']') {
        c = getchar();
      }
    }
    else {
      c = KEY_ESCAPE;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &original_ts);
  }


  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_old);
#elif __WIN32
  c = getch();
#endif

  return c;
}

}
