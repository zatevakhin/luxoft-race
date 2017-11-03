
#ifndef LUXOFT_RACE_ROAD_H
#define LUXOFT_RACE_ROAD_H


#include <vector>
#include <memory>

#include "utils.h"
#include "Player.h"

class Road;


using RoadPtr = std::shared_ptr<Road>;


class Road
{
  public:
    Road(Size size, char garbage);
    ~Road() = default;

  void draw(PlayerPtr player);
    bool isCollided(PlayerPtr player);

  private:
    char garbage_;
    Size size_;
    std::vector<std::string> sections_;


    void genNewSection();
};

#endif //LUXOFT_RACE_ROAD_H
