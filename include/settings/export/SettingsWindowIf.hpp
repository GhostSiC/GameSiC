#pragma once

class SettingsWindowIf
{
public:
    virtual ~SettingsWindowIf() = default;
    // virtual void notifyObserversSettings() = 0;
    // virtual void loadSettings() = 0;
    virtual void changeWindowResolution(float width, float hight) = 0;
    virtual void saveWindowSettings() = 0;
};