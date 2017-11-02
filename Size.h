#ifndef LUXOFT_RACE_SIZE_H
#define LUXOFT_RACE_SIZE_H

#include <iostream>


class Size
{
  public:
    std::size_t width;
    std::size_t height;

    Size(std::size_t w, std::size_t h);
};

#endif //LUXOFT_RACE_SIZE_H
