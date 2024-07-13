#pragma once

class SettingsAdvanceIf
{
public:
    virtual ~SettingsAdvanceIf() = default;
    //virtual void initStartMenu() = 0;
    virtual void changeResolution() = 0;
};