
#include <SettingsAdvance.hpp>


#include <iostream>

#include <StateConst.hpp>

#include <vector>
#include <memory>

#include <SettingsWindowIf.hpp>

SettingsAdvance::SettingsAdvance(std::shared_ptr<SettingsWindowIf> settingsWindow) :
  m_spSettingsWindow{settingsWindow}
{
  //ds
}

void SettingsAdvance::changeWindowResolution()
{
  std::cout << "changeResolution\n";
  m_spSettingsWindow->changeWindowResolution(800,800);
}

void SettingsAdvance::applyWindowChanges()
{
  std::cout << "applyChanges\n";
  m_spSettingsWindow->saveWindowSettings();
  // m_spSettingsWindow->setWindowData(data);
}

// StartMenu::~StartMenu()
// {
//   std::cout << "Delete StartMenu\n";
// }