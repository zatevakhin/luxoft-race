
#ifndef LUXOFT_RACE_ICOLLISION_H
#define LUXOFT_RACE_ICOLLISION_H

#include <vector>

#include "CPlayer.h"


class ICollision {

public:
  virtual bool execute(std::shared_ptr<CPlayer> player,
                       std::vector<std::string>& sections) = 0;

  protected:
    SSize roadSize_{0, 0};
    char colliding_{0};

};

#endif //LUXOFT_RACE_ICOLLISION_H
