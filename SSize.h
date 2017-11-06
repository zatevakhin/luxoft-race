
#ifndef LUXOFT_RACE_SSIZE_H
#define LUXOFT_RACE_SSIZE_H

#include <iostream>


struct SSize
{
  std::size_t width;
  std::size_t height;

  SSize(std::size_t w, std::size_t h);
};

#endif //LUXOFT_RACE_SSIZE_H
