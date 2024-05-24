
#include <StartMenu.hpp>

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

StartMenu::StartMenu(std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager) :
  m_drawableStatus{false},
  m_eventStatus{false},
  m_mainEngineStatus{false},
  sp_mLocalState{std::make_shared<StateManager>(StateOfGame::NONE)},
  m_spAssetsMenager{AssetsMenager::getInstance()},
  sp_mStateGame{stateManager}
{
  std::cout << "Create StartMen\n";
  //m_upButtons = std::make_unique<std::vector<Button>>();
  //sp_mStateMenu = std::make_unique<StateManagerIf>(StateOfGame::MAIN_MENU);
  sp_mLocalState->addState(StateOfGame::MAIN_MENU);


  up_mSettingsMenu = std::make_shared<SettingsMenu>(settingsAdvance, sp_mLocalState);
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
  //sp_mStateGame->pop();
  sp_mStateGame->addState(StateOfGame::GAME);
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
  StandardButtonBuilder builder;

  std::shared_ptr<Button> button = builder
    .initText("Wejdz do gry")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 5))
    .initCallBack(std::bind(&StartMenu::startNewGame, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Ustawienia")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 6))
    .initCallBack(std::bind(&StartMenu::settingsMenu, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Wyjdz z gry")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, (SCREEN_SIZE.y/8) * 7))
    .initCallBack(std::bind(&StartMenu::exitGame, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);
}

void StartMenu::checkState(){

  switch (sp_mLocalState->top())
  {
  case StateOfGame::MAIN_MENU:
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