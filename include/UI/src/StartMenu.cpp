
#include <StartMenu.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

#include <AssetsMenager.hpp>

StartMenu::StartMenu(std::shared_ptr<AssetsMenager> spAssetsMenager) :
  isActive{false}, m_spAssetsMenager{spAssetsMenager}
{
  m_upButtons = std::make_unique<std::vector<Button>>();


  initStartMenu();
  initButton();
}

void StartMenu::initStartMenu()
{

}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if(isActive)
  {
    sf::RectangleShape shape(sf::Vector2f(2000.f, 2000.f));
    shape.setFillColor(sf::Color(100,100,0));

    target.draw(shape);

    for(auto& button : *m_upButtons)
    {
      button.draw(target, sf::RenderStates::Default);
    }
  }
}

void StartMenu::poolEvents(sf::Event& event)
{
  if(isActive)
  {
    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

    if(event.type == sf::Event::MouseButtonPressed)
    {
      for (auto& button : *m_upButtons)
      {
        if (button.getGlobalBounds().contains(mousePosition))
        {
          button.poolEvents(event);
          //handleButtonEvent(button);
        }
      }
    }
  }
}

bool StartMenu::getActive()
{
  return isActive;
}

void StartMenu::setActive(bool active)
{
  isActive = active;
}

void StartMenu::startNewGame()
{
  std::cout << "start game\n";
}

void StartMenu::exitGame()
{
  std::cout << "exit game\n";
}

void StartMenu::initButton()
{
  m_upButtons->emplace_back(Button(TypeButton::StartButton));
  m_upButtons->back().setFont(m_spAssetsMenager->getBasicFont());
  m_upButtons->back().setTexture(m_spAssetsMenager->getBasicTexture());
  m_upButtons->back().setCallBack(std::bind(StartMenu::startNewGame, this));
  m_upButtons->back().setActive(true);

  m_upButtons->emplace_back(Button(TypeButton::SettingsButton));
  m_upButtons->back().setFont(m_spAssetsMenager->getBasicFont());
  m_upButtons->back().setTexture(m_spAssetsMenager->getBasicTexture());
  m_upButtons->back().setActive(true);

  m_upButtons->emplace_back(Button(TypeButton::ExitButton));
  m_upButtons->back().setFont(m_spAssetsMenager->getBasicFont());
  m_upButtons->back().setTexture(m_spAssetsMenager->getBasicTexture());
  m_upButtons->back().setCallBack(std::bind(StartMenu::exitGame, this));
  m_upButtons->back().setActive(true);
}

void StartMenu::handleButtonEvent(Button& button)
{
  switch (button.getTypeButton())
  {
  case TypeButton::StartButton:
    std::cout << "1\n";
    
    break;

  case TypeButton::SettingsButton:
    std::cout << "2\n";
    break;

  case TypeButton::ExitButton:
    std::cout << "3\n";
    //m_spWindow->close(); TODO
    break;

  default:
    break;
  }
}

// void StartMenu::getState()
// {
//   std::cout << "getState\n";
// }