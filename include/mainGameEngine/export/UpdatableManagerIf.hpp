#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

//TO DO: podziel to na 2, Update oraz Draw

class DrawableManagerIf
{
public:
  virtual void Update() = 0;
  virtual bool getActive() = 0;
  virtual void setActive(bool active) = 0;
};