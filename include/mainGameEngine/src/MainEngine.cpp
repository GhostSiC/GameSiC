#include <MainEngine.hpp>

#include <StartMenu.hpp>
// #include <StartMenuView.hpp>
#include <AssetsMenager.hpp>
#include <StateManager.hpp>
// #include <SettingsObserverIf.hpp>
// #include "ConfigData.cpp"

#include <ConfigData.hpp>

#include <iostream>


#include <Settings.hpp>

MainEngine::MainEngine() :
  m_drawableStatus{true},
  m_eventStatus{true},
  m_mainEngineStatus{true}
{
  m_spWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "SFML window"); // 820, 640
  m_spView = std::make_shared<sf::View>(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
  m_spWindow->setView(*m_spView);


  m_spAssetsMenager = std::make_shared<AssetsMenager>();

  up_mStateGameTop = StateOfGame::NONE;

  m_spSettings = std::make_shared<Settings>();
  m_spSettings->registerObserver(this);
  m_spSettingsAdvance = std::make_shared<SettingsAdvance>(m_spSettings);


  shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(2000.f, 2000.f));
  
  shape->setFillColor(sf::Color(75,0,130));


  sp_mStateGame = std::make_shared<StateManager>(StateOfGame::MAIN_MENU);
  std::shared_ptr<StartMenu> sp_mStartMenu = std::make_shared<StartMenu>(m_spAssetsMenager, m_spSettingsAdvance, sp_mStateGame);
  m_spDrawableManager = sp_mStartMenu;
  m_spEventHandler = sp_mStartMenu;
  m_spMainLoopHandler = sp_mStartMenu;
  sp_mStartMenu->setStatus(true);
  
  mainLoop();
}

void MainEngine::mainLoop()
{
  sf::Event event;
  while (m_spWindow->isOpen())
  {

    stateGame();
    //for(auto& mainLoopHandler : m_spMainLoopHandler){
    // if(m_spMainLoopHandler->getMainEngineStatus())
    // {
      m_spMainLoopHandler->mainLoop();
    // }
    poolEvents(event);

    draw(*m_spWindow, sf::RenderStates::Default);
  }
}

void MainEngine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

  m_spWindow->clear();

  target.draw(*shape);
  

  m_spDrawableManager->draw(target, sf::RenderStates::Default);

  m_spWindow->display();
}

void MainEngine::setStatus(bool status)
{
  m_drawableStatus = status;
  m_eventStatus = status;
  m_mainEngineStatus = status;
}

bool MainEngine::getDrawableStatus()
{
  return m_drawableStatus;
}

void MainEngine::setDrawableStatus(bool status)
{
  m_drawableStatus = status;
}

bool MainEngine::getEventStatus()
{
  return m_eventStatus;
}

void MainEngine::setEventStatus(bool status)
{
  m_eventStatus = status;
}

bool MainEngine::getMainEngineStatus()
{
  return m_mainEngineStatus;
}

void MainEngine::setMainEngineStatus(bool status)
{
  m_mainEngineStatus = status;
}

void MainEngine::poolEvents(sf::Event& event)
{
  while (m_spWindow->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      m_spWindow->close();

      m_spEventHandler->poolEvents(event);
  }
}

void MainEngine::updateSettings(std::shared_ptr<Config::WindowData> windowData) // TODO: pomysl czy to ma shared_ptr, unique czy specjalna klasa ktora ma pola tylko zmodyfikowane
{
  std::cout << "MainEngine::updateSettings\n";
  
  if(m_spWindow->getSize() != sf::Vector2u(windowData->resolutionWidth, windowData->resolutionHeight)){
    m_spWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowData->resolutionWidth, windowData->resolutionHeight), "SFML window");
    m_spWindow->setView(*m_spView);
  }
}

void MainEngine::stateGame()
{
  

  if(auto stateGameTop = sp_mStateGame->getState().top(); stateGameTop != up_mStateGameTop){
    switch (stateGameTop)
    {
    case StateOfGame::MAIN_MENU: {
        //
        
      break;
    }
    case StateOfGame::GAME : {
      std::cout << "AAAAAAAAAAAA\n";
        
        sp_mStateGame->addState(StateOfGame::MAIN_MENU);

        // auto sp_mStartMenu = std::make_shared<Menu>();
        // m_spDrawableManager = sp_mStartMenu;
        // m_spEventHandler = sp_mStartMenu;
        //m_spMainLoopHandler = sp_mStartMenu;
        //sp_mStartMenu->setActive(true);
        //sp_mStartMenu->setStatus(true);
        
      break;
    }
    
    default:{
      break;
    }
    }

    up_mStateGameTop = stateGameTop;
  }
}

// void MainEngine::PushState(std::shared_ptr<StateManagerIf>& state)
// {
//   sp_currentlyState = state;
//   sp_gameState.emplace_back(state);
//   //sp_currentlyState->test();
// }