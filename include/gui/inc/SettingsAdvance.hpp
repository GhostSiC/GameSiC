#pragma once
#include <SettingsAdvanceIf.hpp>

#include <memory>

class SettingsAdvance : public SettingsAdvanceIf
{
public:
  SettingsAdvance();
  ~SettingsAdvance() = default;

  void changeResolution() override;

private:

  
};