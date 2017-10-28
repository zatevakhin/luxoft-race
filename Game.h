
#ifndef LUXOFT_RACE_GAME_H
#define LUXOFT_RACE_GAME_H

#include <thread>
#include <random>
#include <vector>
#include <chrono>
#include <conio.h>
#include <iostream>
#include <condition_variable>

#include "Player.h"
#include "Road.h"


#define KEY_UP     72
#define KEY_DOWN   80
#define KEY_LEFT   75
#define KEY_RIGHT  77
#define KEY_ESCAPE 27
#define KEY_ENTER  13


class Game
{
  public:
    Game();
    ~Game();
    void run();

  private:
    std::size_t frameTime_;

    HANDLE consoleHandle_;

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
