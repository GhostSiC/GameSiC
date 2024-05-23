#pragma once

// TODO: delete?
#include <SFML/Graphics.hpp>

const sf::Vector2f SCREEN_SIZE(1920, 1080);

enum class StateOfGame : int16_t
{
  NONE,
  EXIT,
  // MainMenu States
  MAIN_MENU, 
  SettingsMenu, 
  GRAPHIC,
  AUDIO,
  // MainMenu states end

  GAME
};


enum class TypeButton : int16_t
{
  NONE,
  NORMAL,
};

