#pragma once
#include <SettingsWindowIf.hpp>

#include <vector>
#include <memory>

#include <ReadSettingFile.hpp>

class SettingsObserverIf;

namespace Config{
    struct WindowData;
};

class Settings : public SettingsWindowIf 
{
public:
    Settings();
    ~Settings() = default;
    // virtual ~MainEngineIf() = 0;

    void registerObserver(SettingsObserverIf* settingsObserver);

    void changeWindowResolution(float width, float hight);
    void saveWindowSettings();


    // getConfig();
    // setConfig();

private:
    std::shared_ptr<Config::WindowData> m_spConfigWindow;

    void loadSettings();

    std::vector<SettingsObserverIf*> m_vspSettingsObserver;
    //std::shared_ptr<SettingsObserverIf> m_vspSettingsObserver__KOPER;

    void notifyObservers();

};