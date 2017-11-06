
#include "CCollisionItem.h"


CCollisionItem::CCollisionItem(SSize roadSize, char item)
{
  roadSize_ = roadSize;
  colliding_ = item;
}



bool CCollisionItem::execute(std::shared_ptr<CPlayer> player,
                             std::vector<std::string>& sections)
{
  if (sections[roadSize_.height - 2][player->getIndex()] == colliding_) {
    sections[roadSize_.height - 2][player->getIndex()] = ' ';
    player->itemsIter();
  }

  return false;
}
