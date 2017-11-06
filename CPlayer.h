
#ifndef LUXOFT_RACE_CPLAYER_H
#define LUXOFT_RACE_CPLAYER_H

#include <iostream>
#include <memory>


#include "SSize.h"


#define SCORE_ITEM_COST 10


class CPlayer
{
  public:
    CPlayer(SSize roadSize, char symbol);
    ~CPlayer() = default;

    void onKeyLeft();
    void onKeyRight();
    void itemsIter();
    void passedIter();



    char getSymbol() const
    {
      return symbol_;
    }



    std::size_t getIndex() const
    {
      return index_;
    }



    std::size_t getScore() const
    {
      return items_ * SCORE_ITEM_COST;
    }



    std::size_t getPassed() const
    {
      return passed_;
    }



  private:
    char symbol_;
    SSize roadSize_;
    std::size_t index_;
    std::size_t items_;
    std::size_t passed_;

};

#endif //LUXOFT_RACE_CPLAYER_H
