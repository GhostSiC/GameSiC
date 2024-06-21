
#include <StartMenuView.hpp>

#include <vector>

#include <SFML/Graphics.hpp>

#include <AssetsMenager.hpp>
#include <StateManager.hpp>
#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>
#include <StateConst.hpp>
#include <StateManagerIf.hpp>

#include <SettingsMenu.hpp>
#include <Button.hpp>
#include <SettingsAdvance.hpp>
#include <StandardButtonBuilder.hpp>

#include <iostream>


#include <StartMenu_Koper.hpp>

StartMenuView::StartMenuView(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager) :
  m_upStartMenu{std::make_shared<StartMenuKoper>(spAssetsMenager, settingsAdvance, stateManager)},
  m_drawableStatus{false},
  m_eventStatus{false},
  m_mainEngineStatus{false},
  sp_mLocalState{std::make_shared<StateManager>(StateOfGame::NONE)},
  m_spAssetsMenager{spAssetsMenager},
  sp_mStateGame{stateManager}
{
  sp_mLocalState->addState(StateOfGame::MAIN_MENU);

  std::cout << "StartMenuView\n";

  up_mSettingsMenu = std::make_shared<SettingsMenu>(spAssetsMenager, settingsAdvance, sp_mLocalState);
  up_mDrawableInstanceManager.emplace_back(up_mSettingsMenu);
  up_mEventInstanceManager.emplace_back(up_mSettingsMenu);
  
  initButton();
}

void StartMenuView::mainLoop()
{
  checkState();
}

void StartMenuView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if(m_drawableStatus)
  {

    sf::RectangleShape shape(sf::Vector2f(2000.f, 2000.f));
    shape.setFillColor(sf::Color(100,100,0));

    target.draw(shape);

    for(auto& drawable : up_mDrawableManager){
      
      if(drawable->getDrawableStatus()){
        drawable->draw(target, states);
      }
    }
  }
  for(auto& drawableInstance : up_mDrawableInstanceManager){
    if(drawableInstance->getDrawableStatus()){
      drawableInstance->draw(target, states);
    }
  }
}

void StartMenuView::setStatus(bool status)
{
  m_drawableStatus = status;
  m_eventStatus = status;
  m_mainEngineStatus = status;
}

bool StartMenuView::getDrawableStatus()
{
  return m_drawableStatus;
}

void StartMenuView::setDrawableStatus(bool status)
{
  m_drawableStatus = status;
}

bool StartMenuView::getEventStatus()
{
  return m_eventStatus;
}

void StartMenuView::setEventStatus(bool status)
{
  m_eventStatus = status;
}

bool StartMenuView::getMainEngineStatus()
{
  return m_mainEngineStatus;
}

void StartMenuView::setMainEngineStatus(bool status)
{
  m_mainEngineStatus = status;
}

void StartMenuView::poolEvents(sf::Event& event)
{
  if(m_eventStatus)
  {
    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

    if(event.type == sf::Event::MouseButtonPressed)
    {

      for(auto& eventHandler : up_mEventHandler)
      {
        if(eventHandler->getEventStatus())
        {
          eventHandler->poolEvents(event);
        }
      }
    }
  }
  for(auto& eventInstance : up_mEventInstanceManager){
    if(eventInstance->getEventStatus()){
      eventInstance->poolEvents(event);
    }
  }
}

void StartMenuView::initButton()
{
  StandardButtonBuilder builder{m_spAssetsMenager};

  std::shared_ptr<Button> button = builder
    .initText("Wejdz do gry koper")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 5))
    .initCallBack(std::bind(&StartMenuKoper::startNewGame, m_upStartMenu))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Ustawienia koper")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 6))
    .initCallBack(std::bind(&StartMenuKoper::settingsMenu, m_upStartMenu))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Wyjdz z gry koper")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 7))
    .initCallBack(std::bind(&StartMenuKoper::exitGame, m_upStartMenu))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);
}
