
#include "game.h"


Game::Game()
{
  std::srand(unsigned(std::time(nullptr)));
  consoleHandle_ = GetStdHandle(STD_OUTPUT_HANDLE);

  Size console_size = utils::getConsoleSize(consoleHandle_);
  console_size.width = 20; // console_size.width - 4;

  player_ = new Player('@', console_size);
  road_ = new Road(console_size, '*');

  frameTime_ = 200;
}



Game::~Game()
{
  drawThread_.join();
  delete player_;
  delete road_;
}



void Game::onKeyUp()
{
  if (!isPaused_)
    frameTime_ -= (frameTime_ <= 10) ? 0 : 5;
}



void Game::onKeyDown()
{
  if (!isPaused_)
    frameTime_ += (frameTime_ >= 1000) ? 0 : 5;
}



void Game::onKeyEscape()
{
  isRunning_ = false;
  if (isPaused_)
    pauseCondition_.notify_one();
}



void Game::onKeyEnter() {
  isPaused_ = !isPaused_;
  if (!isPaused_)
    pauseCondition_.notify_one();
}



void Game::eventLoop()
{
  while (isRunning_) {
    switch(getch()) {
      case KEY_ESCAPE : onKeyEscape(); break;
      case KEY_ENTER  : onKeyEnter();  break;
      case KEY_UP     : onKeyUp();     break;
      case KEY_DOWN   : onKeyDown();   break;
      case KEY_LEFT :
        if (!isPaused_) {
          player_->onKeyLeft();
        }
        break;
      case KEY_RIGHT :
        if (!isPaused_) {
          player_->onKeyRight();
        }
        break;
    }
  }
}



void Game::run()
{
  isRunning_ = true;
  isPaused_ = false;
  drawThread_ = std::thread(&Game::draw, this);
  eventLoop();
}



void Game::draw()
{
  std::unique_lock<std::mutex> lock(pauseMutex_);

  while (isRunning_) {

    if (isPaused_) {
      std::cout << "PAUSED!" << std::endl;
      pauseCondition_.wait(lock);
    }

    utils::consoleClear(consoleHandle_);

    road_->draw(player_);

    if (road_->isCollided(player_)) {
      std::cout << "GAME OVER!" << std::endl;
      isRunning_ = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(frameTime_));
  }
}
