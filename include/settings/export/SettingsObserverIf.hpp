#pragma once

#include <memory>

namespace Config{
    struct WindowData;
};

class SettingsObserverIf 
{
public:
    virtual ~SettingsObserverIf() = default;
    virtual void updateSettings(std::shared_ptr<Config::WindowData>) = 0;
};