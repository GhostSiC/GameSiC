#pragma once

#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>

class ButtonIf
{
public:
  //virtual ~ButtonIf() = default;
  virtual void setText(std::string&& text) = 0;
  virtual void setSize() = 0;
  virtual void setScale(int scale) = 0;
  virtual void setFontSize() = 0;
  virtual void setOrigin() = 0;
  virtual void setPosition(sf::Vector2f&&) = 0;


  virtual void setFont(std::shared_ptr<sf::Font> font) = 0;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) = 0;
  virtual void setTextureRect(sf::IntRect&& intRect) = 0;


  //virtual void setTexture(std::string&& text) = 0;
  virtual void setCallBack(std::function<void()>) = 0;
  virtual bool getActiveAction() = 0;
  virtual void setActiveAction(bool active) = 0;

  virtual sf::FloatRect getGlobalBounds() const = 0;
};