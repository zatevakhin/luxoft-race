
#include "CRoad.h"


CRoad::CRoad(SSize size, char garbage, char item)
  : size_(size), garbage_(garbage), item_(item)
{
  for (std::size_t i = 0; i < size_.height; ++i) {
    sections_.emplace(sections_.begin() + i, std::string(size_.width, ' '));
  }

  garbageCollision = new CCollisionGarbage(size_, garbage_);
  itemCollision = new CCollisionItem(size_, item_);
}



void CRoad::genNewSection()
{
  std::string section = std::string(size_.width, ' ');
  section[utils::rand(0, static_cast<int>(size_.width))] = garbage_;

  if ((utils::rand(0, 10) % 4) == 0) {
    section[utils::rand(0, static_cast<int>(size_.width))] = item_;
  }

  sections_.emplace(sections_.begin(), section);
}



void CRoad::draw(std::shared_ptr<CPlayer> player,  std::size_t raceTime, std::size_t speed)
{
  genNewSection();
  sections_.pop_back();

  std::string backup = sections_[size_.height - 2];
  sections_[size_.height - 2][player->getIndex()] = player->getSymbol();

  int j = 0;
  for (auto const& i : sections_) {

    std::cout << "'|" << i << "|'";

    switch (j) {
      case 2 :
        std::cout << " Speed  : " << speed << std::endl;
        break;

      case 3 :
        std::cout << " Time   : " << raceTime << "s" << std::endl;
        break;

      case 4 :
        std::cout << " Passed : " << player->getPassed() << std::endl;
        break;

      case 5 :
        std::cout << " Score  : " << player->getScore() << std::endl;
        break;

      default:
        std::cout << std::endl;
    }

    j++;
  }

  player->passedIter();
  sections_[size_.height - 2] = backup;
}



bool CRoad::isCollided(std::shared_ptr<CPlayer> player)
{
  char playerPositionChar = sections_[size_.height - 2][player->getIndex()];

  if (playerPositionChar == garbage_) {
    return garbageCollision->execute(player, sections_);

  } else if (playerPositionChar == item_) {
    return itemCollision->execute(player, sections_);

  }

  return false;
}
