#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

//TO DO: podziel to na 2, Update oraz Draw

class AssetsMenagerIf
{
public:
  virtual ~AssetsMenagerIf() = default;
  virtual std::shared_ptr<sf::Font> getBasicFont() = 0;
  virtual std::shared_ptr<sf::Texture> getBasicTexture() = 0;
};