
#include <StartMenu.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>


StartMenu::StartMenu() :
  isActive{false}
{
}

void StartMenu::initStartMenu()
{
  std::cout << "StartMenu\n";
}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  sf::RectangleShape shape(sf::Vector2f(2000.f, 2000.f));
  shape.setFillColor(sf::Color(0,100,0));

  target.draw(shape);


}

void StartMenu::poolEvents()
{
}

bool StartMenu::getActive()
{
  return isActive;
}

void StartMenu::setActive(bool active)
{
  isActive = active;
}

// void StartMenu::getState()
// {
//   std::cout << "getState\n";
// }