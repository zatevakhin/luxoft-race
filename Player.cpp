
#include "Player.h"


Player::Player(Size roadSize, char symbol)
  : symbol_(symbol), roadSize_(roadSize)
{
  index_ = roadSize_.width / 2;
}



void Player::onKeyLeft()
{
  index_ -= (index_ > 0) ? 1 : 0;
}



void Player::onKeyRight()
{
  index_ += (index_ < (roadSize_.width - 1)) ? 1 : 0;
}



std::size_t Player::getIndex()
{
  return index_;
}
