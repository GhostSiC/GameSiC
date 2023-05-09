#pragma once



class MainEngineIf
{
public:
    // virtual EngineIf() = 0;
    virtual ~MainEngineIf() {};
    virtual void initEngine() = 0;
    virtual void mainLoop() = 0;


    // MainEngineIf(MainEngineIf&&);
    // MainEngineIf(const MainEngineIf&);
    // MainEngineIf& operator=(const MainEngineIf&);
    // MainEngineIf& operator=(MainEngineIf&&);
};