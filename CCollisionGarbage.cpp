
#include "CCollisionGarbage.h"


CCollisionGarbage::CCollisionGarbage(SSize roadSize, char garbage)
{
  roadSize_ = roadSize;
  colliding_ = garbage;
}



bool CCollisionGarbage::execute(std::shared_ptr<CPlayer> player, std::vector<std::string>& sections)
{
  return sections[roadSize_.height - 2][player->getIndex()] == colliding_;
}
