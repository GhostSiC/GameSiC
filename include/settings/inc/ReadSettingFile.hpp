#pragma once
#include <ReadSettingFileIf.hpp>

#include <string>
#include <unordered_map>
#include <memory>

namespace Config{
    struct WindowData;
};

class ReadSettingFile : public ReadSettingFileIf
{
public:
    ReadSettingFile();
    ~ReadSettingFile() = default;

    std::shared_ptr<Config::WindowData> getConfig();

private:
    const std::string m_settingsPath = "../exe/settings";
    std::unordered_map<std::string, std::string> configMap;
    std::shared_ptr<Config::WindowData> ConfigWindow;

    std::string language{"pl"};
    int resolutionWidth{1980};
    int resolutionHeight{1080};
    
    void createSettingsFile();
    void openSettingsFile();

    void parseLanguage();
    void parseResolution();
    
    

};