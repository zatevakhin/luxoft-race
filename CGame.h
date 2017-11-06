
#ifndef LUXOFT_RACE_CGAME_H
#define LUXOFT_RACE_CGAME_H

#include <thread>
#include <random>
#include <vector>
#include <chrono>

#include <iostream>
#include <condition_variable>

#include "Keycodes.h"
#include "CPlayer.h"
#include "CRoad.h"


const int FRAMETIME_DEFAULT = 200;
const int FRAMETIME_MAX     = 1000;
const int FRAMETIME_MIN     = 10;
const int FRAMETIME_STEP    = 5;

const int ROAD_WIDTH        = 20;
const int SPEED_MULTIPLIER  = 10;


class CGame
{
  public:
    CGame();
    ~CGame();
    void run();

  private:
    std::size_t frameTime_;

    std::shared_ptr<CPlayer> player_;
    std::shared_ptr<CRoad> road_;

    bool isRunning_;
    bool isPaused_;

    std::thread drawThread_;
    std::condition_variable pauseCondition_;
    std::mutex pauseMutex_;


    void draw();
    void eventLoop();

    void onKeyUp();
    void onKeyDown();
    void onKeyEscape();
    void onKeyEnter();
};

#endif //LUXOFT_RACE_CGAME_H
