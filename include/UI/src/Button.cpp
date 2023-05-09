
#include <Button.hpp>

#include <iostream>


Button::Button(sf::Vector2f size) :
  isActive{false}
{
  border = std::make_unique<sf::RectangleShape>(size);
  background = std::make_unique<sf::RectangleShape>(size);

  border->setPosition(300.f, 300.f);
}

void Button::initButton()
{

  // shape->setFillColor(sf::Color(186,85,211));

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  target.draw(*background);
  target.draw(*border);

}

void Button::poolEvents()
{
}

bool Button::getActive()
{
  return isActive;
}

void Button::setActive(bool active)
{
  isActive = active;
}
