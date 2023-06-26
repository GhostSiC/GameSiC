#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

//TO DO: podziel to na 2, Update oraz Draw

class AssetsMenagerIf
{
public:

  virtual void loadBasicFont() = 0;
  virtual void loadBasicTexture() = 0;
};