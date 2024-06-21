
#include <Settings.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include <ReadSettingFile.hpp>


#include <memory>


// #include "ConfigData.cpp"
#include <ConfigData.hpp>

#include <SettingsObserverIf.hpp>


Settings::Settings() :
    m_spConfigWindow{std::make_shared<Config::WindowData>()}
{
    loadSettings();
}

void Settings::registerObserver(SettingsObserverIf* settingsObserver)
{
    std::cout << "Settings::registerObserver\n";
    // std::cout << "Settings::registerObserver  m_vspSettingsObserver size:" << m_vspSettingsObserver.size() << '\n';
    m_vspSettingsObserver.push_back(settingsObserver);
    //m_vspSettingsObserver__KOPER = settingsObserver;
    
    // std::cout << "Settings::registerObserver  m_vspSettingsObserver size:" << m_vspSettingsObserver.size() << '\n';
}

void Settings::changeWindowResolution(float width, float hight)
{
    m_spConfigWindow->resolutionWidth = width;
    m_spConfigWindow->resolutionHeight = hight;
}

void Settings::saveWindowSettings()
{
    notifyObservers();
}

void Settings::loadSettings()
{
    ReadSettingFile readSettingFile;
    m_spConfigWindow = readSettingFile.getConfig();
    std::cout << "m_spConfigWindow.language  :" << m_spConfigWindow->language << '\n';
    std::cout << "m_spConfigWindow.resolutionHeight  :" << m_spConfigWindow->resolutionHeight << '\n';
    std::cout << "m_spConfigWindow.resolutionWidth  :" << m_spConfigWindow->resolutionWidth << '\n';
    //notifyObservers();
}

void Settings::notifyObservers()
{
    std::cout << "Settings::notifyObservers  m_vspSettingsObserver size:" << m_vspSettingsObserver.size() << '\n';
    for(auto& observer : m_vspSettingsObserver){
        try
        {
            observer->updateSettings(m_spConfigWindow);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
