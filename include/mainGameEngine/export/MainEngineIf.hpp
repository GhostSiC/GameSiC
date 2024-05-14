#pragma once

class MainEngineIf
{
public:
    virtual ~MainEngineIf() = default;
    virtual void mainLoop() = 0;

    virtual bool getMainEngineStatus() = 0;
    virtual void setMainEngineStatus(bool status) = 0;

    virtual void setStatus(bool status) = 0;

    // MainEngineIf(MainEngineIf&&);
    // MainEngineIf(const MainEngineIf&);
    // MainEngineIf& operator=(const MainEngineIf&);
    // MainEngineIf& operator=(MainEngineIf&&);
};