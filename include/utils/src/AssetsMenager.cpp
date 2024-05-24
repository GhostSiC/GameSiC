#include "AssetsMenager.hpp"

#include <iostream>

std::unique_ptr<AssetsMenager> AssetsMenager::instance = nullptr;
std::once_flag AssetsMenager::initFlag;

AssetsMenager::AssetsMenager()
{
  m_upMainFont = std::make_shared<sf::Font>();
  m_texture = std::make_shared<sf::Texture>();

  loadBasicFont();
  loadBasicTexture();
}

AssetsMenager& AssetsMenager::getInstance()
{
  std::call_once(initFlag, initSingleton);
  return *instance;
}

void AssetsMenager::loadBasicFont()
{
  if (!m_upMainFont->loadFromFile("../assets/font/DragonHunter.otf"))
  {
    std::cout << "nie znaleziono czcionki";
    exit(1);
  }
}

void AssetsMenager::loadBasicTexture()
{
  if (!m_texture->loadFromFile("../assets/buttons.png"))
  {
    std::cout << "nie znaleziono tekstury";
    exit(1);
  }
}

std::shared_ptr<sf::Font> AssetsMenager::getBasicFont()
{
  return m_upMainFont;
}

std::shared_ptr<sf::Texture> AssetsMenager::getBasicTexture()
{
  return m_texture;
}

void AssetsMenager::initSingleton()
{
  instance.reset(new AssetsMenager());
}
