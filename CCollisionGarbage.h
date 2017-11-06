
#ifndef LUXOFT_RACE_CCOLLISIONGARBAGE_H
#define LUXOFT_RACE_CCOLLISIONGARBAGE_H

#include "ICollision.h"


class CCollisionGarbage : public ICollision {

  public:
    CCollisionGarbage(SSize roadSize, char garbage);

    bool execute(std::shared_ptr<CPlayer> player,
                 std::vector<std::string>& sections) override;
};


#endif //LUXOFT_RACE_CCOLLISIONGARBAGE_H
