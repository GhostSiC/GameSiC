#pragma once

class SettingsAdvanceIf
{
public:
    virtual ~SettingsAdvanceIf() = default;
    //virtual void initStartMenu() = 0;
    virtual void changeWindowResolution() = 0;
    virtual void applyWindowChanges() = 0;
};