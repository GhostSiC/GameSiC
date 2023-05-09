#pragma once

#include <memory>
#include <ButtonIf.hpp>

#include <DrawableManagerIf.hpp>

#include <SFML/Graphics.hpp>

#include <PoolEventsIf.hpp>

class Button : public ButtonIf, public DrawableManagerIf, public PoolEventsIf
{
public:
  Button(sf::Vector2f size);
  ~Button() = default;

  void initButton();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  // DrawableManagerIf
  bool getActive() override;
  void setActive(bool active) override;

  void poolEvents() override;

private:
  bool isActive;

  std::unique_ptr<sf::RectangleShape> border;
  std::unique_ptr<sf::RectangleShape> background;
  //std::shared_ptr<sf::RectangleShape> tekst;

};