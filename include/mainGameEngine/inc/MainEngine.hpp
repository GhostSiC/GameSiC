#pragma once

#include <MainEngineIf.hpp>

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>
#include <StateConst.hpp>

#include <SettingsAdvance.hpp>

class Menu;
class StartMenu; 
class StateManagerIf;


class MainEngine : public MainEngineIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  MainEngine();
  ~MainEngine() override = default;

  MainEngine(MainEngine&& ) = delete;
  MainEngine(const MainEngine& ) = delete;
  MainEngine& operator=(const MainEngine& ) = delete;
  MainEngine& operator=(MainEngine&& ) = delete;

  void mainLoop() override;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void setStatus(bool status) override;
  bool getDrawableStatus() override;
  void setDrawableStatus(bool status) override;
  bool getEventStatus() override;
  void setEventStatus(bool status) override;
  bool getMainEngineStatus() override;
  void setMainEngineStatus(bool status) override;

  void poolEvents(sf::Event& event) override;

protected:

private:
  bool m_drawableStatus;
  bool m_eventStatus;
  bool m_mainEngineStatus;

  std::shared_ptr<sf::RenderWindow> m_spWindow;
  std::shared_ptr<sf::View> m_spView;

  std::shared_ptr<DrawableManagerIf> m_spDrawableManager;
  std::shared_ptr<EventHandlerIf> m_spEventHandler;
  std::shared_ptr<MainEngineIf> m_spMainLoopHandler;

  std::shared_ptr<SettingsAdvance> m_spSettingsAdvance;

  std::shared_ptr<StateManagerIf> sp_mStateGame;
  StateOfGame up_mStateGameTop;

  std::shared_ptr<sf::RectangleShape> shape;

  // Functions

  void stateGame();
};