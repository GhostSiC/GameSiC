#pragma once

#include <memory>
#include <StartMenuIf.hpp>

#include <DrawableManagerIf.hpp>

#include <SFML/Graphics.hpp>

#include <PoolEventsIf.hpp>

class StartMenu : public StartMenuIf, public DrawableManagerIf, public PoolEventsIf
{
public:
  StartMenu();
  ~StartMenu() = default;

  // virtual EngineIf() = 0;
  // virtual ~MainEngineIf() = 0;
  void initStartMenu();

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
  std::shared_ptr<sf::View> m_spView;

  bool isActive;
  
};