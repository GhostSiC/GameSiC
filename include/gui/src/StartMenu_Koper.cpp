
#include <StartMenu_Koper.hpp>

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

StartMenuKoper::StartMenuKoper(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager) :
  m_drawableStatus{false},
  m_eventStatus{false},
  m_mainEngineStatus{false},
  sp_mLocalState{std::make_shared<StateManager>(StateOfGame::NONE)},
  m_spAssetsMenager{spAssetsMenager},
  sp_mStateGame{stateManager},
  up_mSettingsMenu{std::make_shared<SettingsMenu>(spAssetsMenager, settingsAdvance, sp_mLocalState)}
{
  sp_mLocalState->addState(StateOfGame::MAIN_MENU);


}


// void StartMenuKoper::mainLoop()
// {
//   checkState();
// }

// void StartMenuKoper::setStatus(bool status)
// {
//   m_drawableStatus = status;
//   m_eventStatus = status;
//   m_mainEngineStatus = status;
// }

// bool StartMenuKoper::getDrawableStatus()
// {
//   return m_drawableStatus;
// }

// void StartMenuKoper::setDrawableStatus(bool status)
// {
//   m_drawableStatus = status;
// }

// bool StartMenuKoper::getEventStatus()
// {
//   return m_eventStatus;
// }

// void StartMenuKoper::setEventStatus(bool status)
// {
//   m_eventStatus = status;
// }

// bool StartMenuKoper::getMainEngineStatus()
// {
//   return m_mainEngineStatus;
// }

// void StartMenuKoper::setMainEngineStatus(bool status)
// {
//   m_mainEngineStatus = status;
// }

void StartMenuKoper::startNewGame()
{
  std::cout << "start game click\n";
  sp_mStateGame->addState(StateOfGame::GAME);
}

void StartMenuKoper::exitGame()
{
  std::cout << "exit game click\n";
}

void StartMenuKoper::settingsMenu()
{
  std::cout << "settings click\n";
  sp_mLocalState->addState(StateOfGame::SettingsMenu);
}

// void StartMenuKoper::checkState(){

//   switch (sp_mLocalState->top())
//   {
//   case StateOfGame::MAIN_MENU:
//   {
//     setStatus(1);
    
//     break;
//   }
//   case StateOfGame::SettingsMenu : 
//   {
//     up_mSettingsMenu->setDrawableStatus(1);
//     up_mSettingsMenu->setEventStatus(1);
//     setDrawableStatus(0);
//     setEventStatus(0);
//     break;
//   }
//   default:
//     break;
//   }
// }