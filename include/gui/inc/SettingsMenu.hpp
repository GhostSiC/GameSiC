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

class SettingsMenu : public StartMenuIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  SettingsMenu(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager);
  ~SettingsMenu() = default;

  //void initStartMenu();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void poolEvents(sf::Event& event) override;

  bool getDrawableStatus() override;
  void setDrawableStatus(bool status) override;
  bool getEventStatus() override;
  void setEventStatus(bool status) override;

private:
  bool m_drawableStatus;
  bool m_eventStatus;

  std::shared_ptr<sf::View> m_spView;
  
  std::unique_ptr<std::vector<Button>> m_upButtons;
  std::vector<std::shared_ptr<Button>> m_upGraphicButtons;
  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;

  std::shared_ptr<SettingsAdvance> m_spSettingsAdvance;

  std::shared_ptr<StateManagerIf> sp_mStateGame;
  std::unique_ptr<StateManagerIf> sp_mStateLocal;

  std::vector<std::shared_ptr<DrawableManagerIf>> up_mDrawableManager;
  std::vector<std::shared_ptr<EventHandlerIf>> up_mEventHandler;

  void initButton();

  void graphicOption();
  void soundOption();
  void backOption();

  void initGraphicButton();
  
};