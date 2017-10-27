
#ifndef LUXSOFTTASK_PLAYER_H
#define LUXSOFTTASK_PLAYER_H

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

#endif //LUXSOFTTASK_PLAYER_H
