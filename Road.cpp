
#include "Road.h"


Road::Road(Size size, char garbage)
  : size_(size), garbage_(garbage)
{
  for (std::size_t i = 0; i < size_.height; ++i) {
    sections_.emplace(sections_.begin() + i, std::string(size_.width, ' '));
  }
}



void Road::genNewSection()
{
  std::string section = std::string(size_.width, ' ');
  section[utils::rand(0, static_cast<int>(size_.width))] = garbage_;
  sections_.emplace(sections_.begin(), section);
}



void Road::draw(Player* player)
{
  genNewSection();
  sections_.pop_back();

  std::string backup = sections_[size_.height - 2];
   sections_[size_.height - 2][player->getIndex()] = '@';

  for (auto const& i : sections_) {
    std::cout << "'|" << i << "|'" << std::endl;
  }

  sections_[size_.height - 2] = backup;
}



bool Road::isCollided(Player* player)
{
  return sections_[size_.height - 2][player->getIndex()] == garbage_;
}
