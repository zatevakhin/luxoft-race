
#ifndef LUXOFT_RACE_CCOLLISIONITEM_H
#define LUXOFT_RACE_CCOLLISIONITEM_H

#include "ICollision.h"

class CCollisionItem : public ICollision {

  public:
    CCollisionItem(SSize roadSize, char item);

    bool execute(std::shared_ptr<CPlayer> player, std::vector<std::string>& sections) override;
};


#endif //LUXOFT_RACE_CCOLLISIONITEM_H
