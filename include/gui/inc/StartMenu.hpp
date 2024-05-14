#pragma once
#include <StartMenuIf.hpp>

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>
#include <MainEngineIf.hpp>

class AssetsMenagerIf;
class Button;
class SettingsMenu;
class StateManagerIf;

class StartMenu : public StartMenuIf, public MainEngineIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  StartMenu(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<StateManagerIf> stateManager);
  //~StartMenu();
  ~StartMenu() = default;

  void mainLoop() override;

  //void initStartMenu();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void setStatus(bool status) override;
  bool getDrawableStatus() override;
  void setDrawableStatus(bool status) override;
  bool getEventStatus() override;
  void setEventStatus(bool status) override;
  bool getMainEngineStatus() override;
  void setMainEngineStatus(bool status) override;

  void poolEvents(sf::Event& event) override;

  void startNewGame();
  void exitGame();
  void settingsMenu();

private:
  bool m_drawableStatus;
  bool m_eventStatus;
  bool m_mainEngineStatus;

  void initButton();

  std::shared_ptr<sf::View> m_spView;
  
  std::vector<std::shared_ptr<Button>> m_vButtons;
  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;


  std::shared_ptr<SettingsMenu> up_mSettingsMenu;


  std::shared_ptr<StateManagerIf> sp_mStateGame;
  std::shared_ptr<StateManagerIf> sp_mLocalState;

  std::vector<std::shared_ptr<DrawableManagerIf>> up_mDrawableManager;
  std::vector<std::shared_ptr<DrawableManagerIf>> up_mDrawableInstanceManager;
  std::vector<std::shared_ptr<EventHandlerIf>> up_mEventHandler;
  std::vector<std::shared_ptr<EventHandlerIf>> up_mEventInstanceManager;
  
  // Buttons
  std::shared_ptr<Button> settingsButton;

  void checkState();

};