#pragma once

#include <MainEngineIf.hpp>

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <PoolEventsIf.hpp>

#include <Menu.hpp>
#include <StartMenu.hpp>


class MainEngine : public MainEngineIf, public DrawableManagerIf, public PoolEventsIf
{
public:
  MainEngine();
  ~MainEngine() override = default;

  MainEngine(MainEngine&& ) = delete;
  MainEngine(const MainEngine& ) = delete;
  MainEngine& operator=(const MainEngine& ) = delete;
  MainEngine& operator=(MainEngine&& ) = delete;

  void initEngine() override;
  void mainLoop() override;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  bool getActive() override;
  void setActive(bool active) override;

  void poolEvents() override;

  //void PopState();

  void removeState();


protected:

private:
  std::shared_ptr<sf::RenderWindow> m_spWindow;
  std::shared_ptr<sf::View> m_spView;

  std::shared_ptr<Menu> sp_mMenu;
  std::shared_ptr<StartMenu> sp_mStartMenu;

  std::vector<std::shared_ptr<DrawableManagerIf>> sp_mDrawable;

  bool isActive;

  std::shared_ptr<sf::RectangleShape> shape;
  //std::unique_ptr<DrawableManagerIf> sp_mDrawable;
};