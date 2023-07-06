#pragma once

#include <SFML/Graphics/Drawable.hpp>

class EventHandlerIf
{
public:
  virtual void poolEvents(sf::Event& event) = 0;
  virtual bool getActive() = 0;
  virtual void setActive(bool active) = 0;
};