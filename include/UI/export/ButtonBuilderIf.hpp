#pragma once

#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>

class Button;

class ButtonBuilderIf
{
public:
  virtual ~ButtonBuilderIf() = default;
  virtual std::shared_ptr<Button> build() = 0;
  virtual void reset() = 0;

  virtual ButtonBuilderIf& initText(std::string&& text) = 0;
  virtual ButtonBuilderIf& initFontSize(sf::Vector2f&& scale) = 0;
  virtual ButtonBuilderIf& initFont(std::shared_ptr<sf::Font> font) = 0;
  virtual ButtonBuilderIf& initFontColor(sf::Color color) = 0;

  virtual ButtonBuilderIf& initScale(sf::Vector2f&&) = 0;
  virtual ButtonBuilderIf& initPosition(sf::Vector2f&&) = 0;

  virtual ButtonBuilderIf& initTexture(std::shared_ptr<sf::Texture> texture, sf::IntRect&& intRect) = 0;

  virtual ButtonBuilderIf& initCallBack(std::function<void()>) = 0;

  //virtual void setTexture(std::string&& text) = 0;
};