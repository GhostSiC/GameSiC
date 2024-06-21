#pragma once
#include <StartMenuIf.hpp>

#include <memory>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>

class AssetsMenagerIf;
class StateManagerIf;
class Button;
class SettingsAdvance;
class SettingsMenu;

class StartMenuKoper : public StartMenuIf
{
public:
  StartMenuKoper(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager);
  ~StartMenuKoper() = default;

  //void initStartMenu();

  // bool getDrawableStatus() override;
  // void setDrawableStatus(bool status) override;
  // bool getEventStatus() override;
  // void setEventStatus(bool status) override;

  void startNewGame();
  void settingsMenu();
  void exitGame();


 private:
  bool m_drawableStatus;
  bool m_eventStatus;
  bool m_mainEngineStatus;

  std::shared_ptr<SettingsAdvance> m_spSettingsAdvance;
  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;

  std::shared_ptr<StateManagerIf> sp_mStateGame;
  std::shared_ptr<StateManagerIf> sp_mLocalState;

  std::shared_ptr<SettingsMenu> up_mSettingsMenu;

  // std::vector<std::shared_ptr<DrawableManagerIf>> up_mDrawableManager;
  // std::vector<std::shared_ptr<EventHandlerIf>> up_mEventHandler;

  void graphicOption();
  void soundOption();
  void backOption();

  void initGraphicButton();
  
};