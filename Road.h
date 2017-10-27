
#ifndef LUXSOFTTASK_ROAD_H
#define LUXSOFTTASK_ROAD_H


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

#endif //LUXSOFTTASK_ROAD_H
