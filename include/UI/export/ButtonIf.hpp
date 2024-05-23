#pragma once

#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>

class ButtonIf
{
public:
  //virtual ~ButtonIf() = default;
  virtual void setText(const std::string& text) = 0;
  virtual void setSize() = 0;
  virtual void setScale(const sf::Vector2f& scale) = 0;
  virtual void setFontSize(sf::Vector2f scale) = 0;
  virtual void setFontColor(sf::Color color) = 0;
  virtual void setOrigin() = 0;
  virtual void setPosition(const sf::Vector2f&) = 0;


  virtual void setFont(std::shared_ptr<sf::Font> font) = 0;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) = 0;
  virtual void setTextureRect(const sf::IntRect& intRect) = 0;


  //virtual void setTexture(std::string&& text) = 0;
  virtual void setCallBack(std::function<void()>) = 0;
  virtual bool getActiveAction() = 0;
  virtual void setActiveAction(bool active) = 0;

  virtual sf::FloatRect getGlobalBounds() const = 0;
};