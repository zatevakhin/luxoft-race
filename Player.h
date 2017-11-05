
#ifndef LUXOFT_RACE_PLAYER_H
#define LUXOFT_RACE_PLAYER_H

#include <iostream>
#include <memory>

#include "Size.h"


class Player;


using PlayerPtr = std::shared_ptr<Player>;


class Player
{
  public:
    Player(Size roadSize, char symbol);
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
