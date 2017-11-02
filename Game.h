
#ifndef LUXOFT_RACE_GAME_H
#define LUXOFT_RACE_GAME_H

#include <thread>
#include <random>
#include <vector>
#include <chrono>

#include <iostream>
#include <condition_variable>

#include "Keycodes.h"
#include "Player.h"
#include "Road.h"


class Game
{
  public:
    Game();
    ~Game();
    void run();

  private:
    std::size_t frameTime_;
    Player* player_;
    Road* road_;

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

#endif //LUXOFT_RACE_GAME_H
