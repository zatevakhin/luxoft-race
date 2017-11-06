
#ifndef LUXOFT_RACE_KEYCODES_H
#define LUXOFT_RACE_KEYCODES_H

namespace Keycode {

const int ESCAPE = 27;

#ifdef __linux__
  const int UP    = 65;
  const int DOWN  = 66;
  const int LEFT  = 68;
  const int RIGHT = 67;
  const int ENTER = 10;
#elif _WIN32
  const int UP    = 72;
  const int DOWN  = 80;
  const int LEFT  = 75;
  const int RIGHT = 77;
  const int ENTER = 13;
#endif

}

#endif //LUXOFT_RACE_KEYCODES_H
