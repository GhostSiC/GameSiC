
#include <ReadSettingFile.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <algorithm>


#include <ConfigData.hpp>

ReadSettingFile::ReadSettingFile() :
    ConfigWindow{std::make_shared<Config::WindowData>()}
{
    std::cout << "\n ReadSettingFile::ReadSettingFile  \n\n";

    try {
        openSettingsFile();
    } catch (const std::exception& e) {
        createSettingsFile();
        return;
    }

    try {
        parseLanguage();
        parseResolution();
    } catch (const std::exception& e) {
        createSettingsFile();
        return;
    }

}

std::shared_ptr<Config::WindowData> ReadSettingFile::getConfig()
{
    return ConfigWindow;
}

void ReadSettingFile::createSettingsFile()
{
    std::ofstream outputFile(m_settingsPath);
    if (!outputFile) {
        throw std::runtime_error("Error: Could not create the file " + m_settingsPath);
    }
    std::cout << "nie dziala\n";
}

void ReadSettingFile::openSettingsFile()
{
    std::ifstream configFile(m_settingsPath);

    if (!configFile) {
        throw std::runtime_error("Error: Could not open the file " + m_settingsPath);
    }

    std::cout << "dziala\n";

    std::string line;

    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);
        std::string key;
        if (std::getline(lineStream, key, '=')) {
            std::string value;
            if (std::getline(lineStream, value)) {
                configMap[key] = value;
            }
        }
    }
}

void ReadSettingFile::parseLanguage()
{
    auto it = configMap.find("language");
    if (it != configMap.end()) {
        ConfigWindow->language = it->second;
    } else {
        throw std::runtime_error("Error: Missing 'language' key in the configuration file.");
    }
    std::cout << "parseLanguage\n";
}

void ReadSettingFile::parseResolution()
{
    auto it = configMap.find("resolution");
    if (it != configMap.end()) {
        std::string value = it->second;
        if (value.find('x') != std::string::npos) {
            // Format: _x_
            std::replace(value.begin(), value.end(), 'x', ' ');
            std::istringstream resStream(value);
            resStream >> ConfigWindow->resolutionWidth >> ConfigWindow->resolutionHeight;
        } else {
            throw std::runtime_error("Error: Unknown resolution format in the configuration file.");
        }
    } else {
        throw std::runtime_error("Error: Missing 'resolution' key in the configuration file.");
    }
    std::cout << "parseResolution\n";
}
