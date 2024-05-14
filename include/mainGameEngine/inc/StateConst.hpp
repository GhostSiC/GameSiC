#pragma once

const sf::Vector2f SCREEN_SIZE(1920, 1080);

enum class StateOfGame : int16_t
{
  None,
  Exit,
  // MainMenu States
  MainMenu,
  SettingsMenu,
  // MainMenu states end

  Game,
  Menu
};


enum class TypeButton : int16_t
{
  NONE,
  NORMAL,
};

