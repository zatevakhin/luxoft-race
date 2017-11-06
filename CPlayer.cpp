
#include "CPlayer.h"


CPlayer::CPlayer(SSize roadSize, char symbol)
  : symbol_(symbol), roadSize_(roadSize)
{
  index_ = roadSize_.width / 2;
  passed_ = 0;
  items_ = 0;
}



void CPlayer::onKeyLeft()
{
  index_ -= (index_ > 0) ? 1 : 0;
}



void CPlayer::onKeyRight()
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
