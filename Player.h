
#ifndef LUXOFT_RACE_PLAYER_H
#define LUXOFT_RACE_PLAYER_H

#include <iostream>

#include "Size.h"


class Player
{
  public:
    Player(char symbol, Size roadSize);
    ~Player() = default;

    void onKeyLeft();
    void onKeyRight();

    std::size_t getIndex();

  private:
    Size roadSize_;
    std::size_t index_;
    char symbol_;

};

#endif //LUXOFT_RACE_PLAYER_H
