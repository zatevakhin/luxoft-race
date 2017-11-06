
#include "CGame.h"


CGame::CGame()
{
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  SSize console_size = utils::getConsoleSize();
  console_size.width = ROAD_WIDTH;

  player_ = std::make_shared<CPlayer>(console_size, '^');
  road_ = std::make_shared<CRoad>(console_size, '#', '+');

  frameTime_ = FRAMETIME_DEFAULT;
}



CGame::~CGame()
{
  drawThread_.join();
}



void CGame::onKeyUp()
{
  if (!isPaused_)
    frameTime_ -= (frameTime_ <= FRAMETIME_MIN) ? 0 : FRAMETIME_STEP;
}



void CGame::onKeyDown()
{
  if (!isPaused_)
    frameTime_ += (frameTime_ >= FRAMETIME_MAX) ? 0 : FRAMETIME_STEP;
}



void CGame::onKeyEscape()
{
  isRunning_ = false;
  if (isPaused_)
    pauseCondition_.notify_one();
}



void CGame::onKeyEnter() {
  isPaused_ = !isPaused_;
  if (!isPaused_)
    pauseCondition_.notify_one();
}



void CGame::eventLoop()
{
  while (isRunning_) {
    int c = utils::getInputChar();
    switch(c) {
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



void CGame::run()
{
  isRunning_ = true;
  isPaused_ = false;
  drawThread_ = std::thread(&CGame::draw, this);
  eventLoop();
}



void CGame::draw()
{
  std::unique_lock<std::mutex> lock(pauseMutex_);
  auto started_at = std::chrono::system_clock::now();

  while (isRunning_) {

    if (isPaused_) {
      std::cout << "PAUSED!" << std::endl;
      pauseCondition_.wait(lock);
    }

    utils::consoleClear();

    auto passed = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now() - started_at
    );

    road_->draw(player_, passed.count(), (FRAMETIME_MAX / frameTime_) * 10);

    if (road_->isCollided(player_)) {
      std::cout << "It`s end of game, press any key to exit." << std::endl;
      isRunning_ = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(frameTime_));
  }
}
