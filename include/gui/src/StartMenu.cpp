
#include <StartMenu.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

#include <AssetsMenager.hpp>
#include <StateManager.hpp>

#include <StateConst.hpp>

#include <SettingsMenu.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>

#include <Button.hpp>
#include <StateManagerIf.hpp>
#include <SettingsMenu.hpp>

#include <vector>

StartMenu::StartMenu(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<StateManagerIf> stateManager) :
  m_drawableStatus{false},
  m_eventStatus{false},
  m_mainEngineStatus{false},
  sp_mLocalState{std::make_shared<StateManager>(StateOfGame::None)},
  m_spAssetsMenager{spAssetsMenager}, sp_mStateGame{stateManager}
{
  std::cout << "Create StartMen\n";
  //m_upButtons = std::make_unique<std::vector<Button>>();
  //sp_mStateMenu = std::make_unique<StateManagerIf>(StateOfGame::MainMenu);
  sp_mLocalState->addState(StateOfGame::MainMenu);


  up_mSettingsMenu = std::make_shared<SettingsMenu>(spAssetsMenager, sp_mLocalState);
  up_mDrawableInstanceManager.emplace_back(up_mSettingsMenu);
  up_mEventInstanceManager.emplace_back(up_mSettingsMenu);

  initButton();
}

// StartMenu::~StartMenu()
// {
//   std::cout << "Delete StartMenu\n";
// }

void StartMenu::mainLoop()
{
  //std::cout << "sp_mLocalState->top(): " << static_cast<int>(sp_mLocalState->top()) << '\n';
  checkState();
}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
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

void StartMenu::poolEvents(sf::Event& event)
{
  //std::cout << "poolEvents isActive:" << isActive << '\n';
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

void StartMenu::setStatus(bool status)
{
  m_drawableStatus = status;
  m_eventStatus = status;
  m_mainEngineStatus = status;
}

bool StartMenu::getDrawableStatus()
{
  return m_drawableStatus;
}

void StartMenu::setDrawableStatus(bool status)
{
  m_drawableStatus = status;
}

bool StartMenu::getEventStatus()
{
  return m_eventStatus;
}

void StartMenu::setEventStatus(bool status)
{
  m_eventStatus = status;
}

bool StartMenu::getMainEngineStatus()
{
  return m_mainEngineStatus;
}

void StartMenu::setMainEngineStatus(bool status)
{
  m_mainEngineStatus = status;
}

void StartMenu::startNewGame()
{
  std::cout << "start game\n";
  std::cout << "start game click\n";
  //sp_mStateGame->deleteState();
  //sp_mStateGame->addState(StateOfGame::Game);
  //m_vButtons.back()->setText("test") ;
}

void StartMenu::exitGame()
{
  std::cout << "exit game\n";
  std::cout << "exit game click\n";
}

void StartMenu::settingsMenu()
{
  std::cout << "settings \n";
  std::cout << "settings click\n";
  sp_mLocalState->addState(StateOfGame::SettingsMenu);
  //checkState();
}

void StartMenu::initButton()
{
  std::shared_ptr<Button> button = std::make_shared<Button>(m_spAssetsMenager, "Wejdz do gry");
  button->setCallBack(std::bind(&StartMenu::startNewGame, this));
  button->setPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 5));

  
  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button.reset();

  button = std::make_shared<Button>(m_spAssetsMenager, "Ustawienia");
  button->setCallBack(std::bind(&StartMenu::settingsMenu, this));
  button->setPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 6));
  
  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button.reset();

  button = std::make_shared<Button>(m_spAssetsMenager, "Wyjdz z gry");
  button->setCallBack(std::bind(&StartMenu::exitGame, this));
  button->setPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 7));
  
  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);
}

void StartMenu::checkState(){

  switch (sp_mLocalState->top())
  {
  case StateOfGame::MainMenu:
  {
    setStatus(1);
    
    break;
  }
  case StateOfGame::SettingsMenu : 
  {
    up_mSettingsMenu->setDrawableStatus(1);
    up_mSettingsMenu->setEventStatus(1);
    setDrawableStatus(0);
    setEventStatus(0);
    break;
  }
  default:
    break;
  }
}
// void StartMenu::getState()
// {
//   std::cout << "getState\n";
// }