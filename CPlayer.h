
#ifndef LUXOFT_RACE_CPLAYER_H
#define LUXOFT_RACE_CPLAYER_H

#include <iostream>
#include <memory>
#include <vector>

#include "SSize.h"


const int SCORE_ITEM_COST = 10;


class CPlayer
{
  public:
    CPlayer(SSize roadSize, char carChar);
    ~CPlayer() = default;

    void moveLeft();
    void moveRight();

    bool isAutopilotState();
    void toggleAutopilot();
    void useAutopilot(const std::vector<std::string>& sections, char garbage);

    void itemsIter();
    void passedIter();



    inline char getCarChar () const
    {
      return carChar_;
    }



    inline std::size_t getIndex() const
    {
      return index_;
    }



    inline std::size_t getScore() const
    {
      return items_ * SCORE_ITEM_COST;
    }



    inline std::size_t getPassed() const
    {
      return passed_;
    }



  private:
    char carChar_;

    bool autopilotEnabled_;

    SSize roadSize_;

    std::size_t index_;
    std::size_t items_;
    std::size_t passed_;

};

#endif //LUXOFT_RACE_CPLAYER_H
