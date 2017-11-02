
#ifndef LUXOFT_RACE_KEYCODES_H
#define LUXOFT_RACE_KEYCODES_H

#define KEY_ESCAPE   27

#ifdef __linux__
  #define KEY_UP     65
  #define KEY_DOWN   66
  #define KEY_LEFT   68
  #define KEY_RIGHT  67
  #define KEY_ENTER  10
#elif _WIN32
  #define KEY_UP     72
  #define KEY_DOWN   80
  #define KEY_LEFT   75
  #define KEY_RIGHT  77
  #define KEY_ENTER  13
#endif

#endif //LUXOFT_RACE_KEYCODES_H
