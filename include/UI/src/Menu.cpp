
#include <Menu.hpp>

#include <Button.hpp>

#include <iostream>


Menu::Menu() :
  isActive{false}
{
}

void Menu::initMenu()
{
  shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(2000.f, 2000.f));
  
  shape->setFillColor(sf::Color(0,85,211));

  //m_upExitButton = std::make_unique<Button>("Test", sf::Vector2f(100.f, 50.f));

}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  target.draw(*shape);


  //m_upExitButton->draw(target, sf::RenderStates::Default);
}

void Menu::poolEvents()
{
}

bool Menu::getActive()
{
  return isActive;
}

void Menu::setActive(bool active)
{
  isActive = active;
}
