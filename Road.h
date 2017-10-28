
#ifndef LUXOFT_RACE_ROAD_H
#define LUXOFT_RACE_ROAD_H


#include <vector>

#include "utils.h"
#include "Player.h"


class Road
{
  public:
    Road(Size size, char garbage);
    ~Road() = default;

    void draw(Player* player);
    bool isCollided(Player* player);

  private:
    char garbage_;
    Size size_;
    std::vector<std::string> sections_;


    void genNewSection();
};

#endif //LUXOFT_RACE_ROAD_H
