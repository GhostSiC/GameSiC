#pragma once

#include <SFML/Graphics/Drawable.hpp>

class EventHandlerIf
{
public:
  virtual ~EventHandlerIf() = default;
  virtual void poolEvents(sf::Event& event) = 0;
  virtual bool getEventStatus() = 0;
  virtual void setEventStatus(bool status) = 0;
};