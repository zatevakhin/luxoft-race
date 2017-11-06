
#ifndef LUXOFT_RACE_CROAD_H
#define LUXOFT_RACE_CROAD_H

#include <vector>
#include <memory>

#include "utils.h"
#include "CPlayer.h"
#include "CCollisionGarbage.h"
#include "CCollisionItem.h"


class CRoad
{
  public:
    CRoad(SSize size, char garbage, char item);
    ~CRoad() = default;

    void draw(std::shared_ptr<CPlayer> player,
              std::size_t raceTime, std::size_t speed);

    bool isCollided(std::shared_ptr<CPlayer> player);

  private:
    char garbage_;
    char item_;

    SSize size_;

    std::vector<std::string> sections_;

    std::shared_ptr<ICollision> garbageCollision_;
    std::shared_ptr<ICollision> itemCollision_;


    void genNewSection();
};

#endif //LUXOFT_RACE_CROAD_H
