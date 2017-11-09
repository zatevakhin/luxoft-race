
#include "CPlayer.h"


CPlayer::CPlayer(SSize roadSize, char carChar)
  : carChar_(carChar), roadSize_(roadSize)
{
  autopilotEnabled_ = false;
  index_ = roadSize_.width / 2;
  passed_ = 0;
  items_ = 0;
}



void CPlayer::moveLeft()
{
  index_ -= (index_ > 0) ? 1 : 0;
}



void CPlayer::moveRight()
{
  index_ += (index_ < (roadSize_.width - 1)) ? 1 : 0;
}



void CPlayer::itemsIter()
{
  items_++;
}



void CPlayer::passedIter()
{
  passed_++;
}


bool CPlayer::isAutopilotState()
{
  return autopilotEnabled_;
}


void CPlayer::toggleAutopilot()
{
  autopilotEnabled_ = !autopilotEnabled_;
}


void CPlayer::useAutopilot(const std::vector<std::string>& sections,
                           char garbage)
{

  bool carOnRight = index_ >= (roadSize_.width / 2);

  bool obstacleInFront = sections[roadSize_.height - 3][index_] == garbage;

  bool onRightClear = sections[roadSize_.height - 2][index_ - 1] != garbage;
  bool onNextRightClear = sections[roadSize_.height - 3][index_ - 1] != garbage;

  bool onLeftClear = sections[roadSize_.height - 2][index_ + 1] != garbage;
  bool onNextLeftClear = sections[roadSize_.height - 3][index_ + 1] != garbage;


  if (carOnRight) {

    if (obstacleInFront && onLeftClear && onNextLeftClear) {
      moveLeft();
    }
    else if (obstacleInFront && onRightClear && onNextRightClear) {
      moveRight();
    }

  }
  else {

    if (obstacleInFront && onRightClear && onNextRightClear) {
      moveRight();
    }
    else if (obstacleInFront && onLeftClear && onNextLeftClear) {
      moveLeft();
    }

  }

}
