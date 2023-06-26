
#include <StartMenu.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

#include <AssetsMenager.hpp>

#include <ButtonManager.hpp> 


StartMenu::StartMenu(std::shared_ptr<AssetsMenager> spAssetsMenager) :
  isActive{false}, m_spAssetsMenager{spAssetsMenager}
{

  std::cout << "StartMenu\n";
  m_upStartButton = std::make_unique<std::vector<Button>>();

  m_upStartButton->emplace_back(Button(TypeButton::StartButton));
  m_upStartButton->back().setFont(m_spAssetsMenager->getBasicFont());
  m_upStartButton->back().setTexture(m_spAssetsMenager->getBasicTexture());
  m_upStartButton->back().setActive(true);

  m_upStartButton->emplace_back(Button(TypeButton::ExitButton));
  m_upStartButton->back().setFont(m_spAssetsMenager->getBasicFont());
  m_upStartButton->back().setTexture(m_spAssetsMenager->getBasicTexture());
  m_upStartButton->back().setActive(true);

  initStartMenu();

}

void StartMenu::initStartMenu()
{

}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  sf::RectangleShape shape(sf::Vector2f(2000.f, 2000.f));
  shape.setFillColor(sf::Color(100,100,0));

  target.draw(shape);

  for(auto& button : *m_upStartButton)
  {
    button.draw(target, sf::RenderStates::Default);
  }
}

void StartMenu::poolEvents()
{
}

bool StartMenu::getActive()
{
  return isActive;
}

void StartMenu::setActive(bool active)
{
  isActive = active;
}

// void StartMenu::getState()
// {
//   std::cout << "getState\n";
// }