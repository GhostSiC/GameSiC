#pragma once
#include <SettingsAdvanceIf.hpp>

#include <memory>

class SettingsWindowIf;

class SettingsAdvance : public SettingsAdvanceIf
{
public:
  SettingsAdvance(std::shared_ptr<SettingsWindowIf> settingsWindow);
  ~SettingsAdvance() = default;

  void changeWindowResolution() override;
  void applyWindowChanges() override;

private:

  std::shared_ptr<SettingsWindowIf> m_spSettingsWindow;
};