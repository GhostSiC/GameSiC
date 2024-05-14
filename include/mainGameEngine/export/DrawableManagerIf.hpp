#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

class DrawableManagerIf
{
public:
  virtual ~DrawableManagerIf() = default; 
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
  virtual bool getDrawableStatus() = 0;
  virtual void setDrawableStatus(bool status) = 0;

};