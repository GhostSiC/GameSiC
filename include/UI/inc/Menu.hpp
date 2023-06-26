#pragma once

#include <MenuIf.hpp>

#include <memory>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <PoolEventsIf.hpp>

class Button;

class Menu : public MenuIf, public DrawableManagerIf, public PoolEventsIf
{
public:
  Menu();
  ~Menu() = default;

  // virtual EngineIf() = 0;
  // virtual ~MainEngineIf() = 0;
  void initMenu();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void poolEvents() override;
  bool getActive() override;
  void setActive(bool active) override;

  //void getState() override;


  // void addState();
  // void removeState();

  // void Update() override;
  // void Draw() override;
private:
  //std::shared_ptr<sf::RenderWindow> m_spWindow;

  bool isActive;

  std::shared_ptr<sf::View> m_spView;
  std::shared_ptr<sf::RectangleShape> shape;

  std::unique_ptr<Button> m_upExitButton;

};