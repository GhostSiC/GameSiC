
#include <SettingsMenu.hpp>

#include <SFML/Graphics.hpp>

#include <AssetsMenager.hpp>
#include <Button.hpp>
#include <StateConst.hpp>
#include <StateManager.hpp>
#include <StateManagerIf.hpp>
#include <SettingsAdvance.hpp>

#include <iostream>

// namespace
// {
//   enum class StateOfSettingsMenu : int16_t
//   {
//     None,
//     GRAPHIC,
//     AUDIO
//   };
// }

SettingsMenu::SettingsMenu(std::shared_ptr<AssetsMenagerIf> spAssetsMenager, std::shared_ptr<SettingsAdvance> settingsAdvance, std::shared_ptr<StateManagerIf> stateManager) :
  m_drawableStatus{false},
  m_eventStatus{false},
  m_spAssetsMenager{spAssetsMenager},
  m_spSettingsAdvance{settingsAdvance},
  sp_mStateGame{stateManager},
  sp_mStateLocal{std::make_unique<StateManager>(StateOfGame::NONE)}
{
  //m_upButtons = std::make_unique<std::vector<Button>>();

  sp_mStateLocal->addState(StateOfGame::GRAPHIC);

  initButton();
  initGraphicButton();
}

void SettingsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if(m_drawableStatus)
  {
    sf::RectangleShape shape(sf::Vector2f(2000.f, 2000.f));
    shape.setFillColor(sf::Color(100,100,100));

    target.draw(shape);

    for(auto& drawable : up_mDrawableManager){
      if(drawable->getDrawableStatus()){
        if(drawable->getDrawableStatus() == 0 ) std::cout << "drawable->getDrawableStatus(): " << drawable->getDrawableStatus() << '\n';
        drawable->draw(target, states);
      }
    }
  }
}

void SettingsMenu::poolEvents(sf::Event& event)
{
  if(m_eventStatus)
  {
    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

    if(event.type == sf::Event::MouseButtonPressed)
    {
      for(auto& eventHandler : up_mEventHandler)
      {
        if(eventHandler->getEventStatus())
        {
          eventHandler->poolEvents(event);
        }
      }
    }
  }
}

bool SettingsMenu::getDrawableStatus()
{
  return m_drawableStatus;
}

void SettingsMenu::setDrawableStatus(bool status)
{
  m_drawableStatus = status;
}

bool SettingsMenu::getEventStatus()
{
  return m_eventStatus;
}

void SettingsMenu::setEventStatus(bool status)
{
  m_eventStatus = status;
}

void SettingsMenu::graphicOption()
{
  std::cout << "graphicOption\n";
  for(auto& graphicButtons : m_upGraphicButtons)
  {
    graphicButtons->setDrawableStatus(1);
    graphicButtons->setEventStatus(1);
  }
  
  //sp_mStateGame->deleteState();
  //sp_mStateGame->addState(StateOfGame::GAME);
}

void SettingsMenu::soundOption()
{
  std::cout << "soundOption\n";
  for(auto& graphicButtons : m_upGraphicButtons)
  {
    graphicButtons->setDrawableStatus(0);
    graphicButtons->setEventStatus(0);
  }
}

void SettingsMenu::backOption()
{
  std::cout << "backOption\n";
  setDrawableStatus(0);
  setEventStatus(0);
  sp_mStateGame->pop();
}

void SettingsMenu::initButton()
{
  std::cout << "SettingsMenu::initButton\n";

  // std::shared_ptr<Button> button = std::make_shared<Button>(m_spAssetsMenager, "Powrot");
  // button->setCallBack(std::bind(&SettingsMenu::backOption, this));
  // button->setPosition(sf::Vector2f(SCREEN_SIZE.x/8, SCREEN_SIZE.y/8));
  // up_mDrawableManager.emplace_back(button);
  // up_mEventHandler.emplace_back(button);

  // button.reset();

  // button = std::make_shared<Button>(m_spAssetsMenager, "Grafika");
  // button->setCallBack(std::bind(&SettingsMenu::graphicOption, this));
  // button->setPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 5, SCREEN_SIZE.y/8));

  // up_mDrawableManager.emplace_back(button);
  // up_mEventHandler.emplace_back(button);

  // button.reset();

  // button = std::make_shared<Button>(m_spAssetsMenager, "Dzwiek");
  // button->setCallBack(std::bind(&SettingsMenu::soundOption, this));
  // button->setPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 3, SCREEN_SIZE.y/8));
  
  // up_mDrawableManager.emplace_back(button);
  // up_mEventHandler.emplace_back(button);

}

void SettingsMenu::initGraphicButton()
{
  // m_upGraphicButtons.push_back(std::make_shared<Button>(m_spAssetsMenager, "resolution"));
  // m_upGraphicButtons.back()->setDrawableStatus(0);
  // m_upGraphicButtons.back()->setEventStatus(0);
  // m_upGraphicButtons.back()->setCallBack(std::bind(&SettingsAdvance::changeResolution , m_spSettingsAdvance));
  // m_upGraphicButtons.back()->setPosition(sf::Vector2f(SCREEN_SIZE.x/2, SCREEN_SIZE.y/2));

  // up_mDrawableManager.emplace_back(m_upGraphicButtons.back());
  // up_mEventHandler.emplace_back(m_upGraphicButtons.back());

  // button.reset();

  // button = std::make_shared<Button>(m_spAssetsMenager, "Grafika");
  // button->setCallBack(std::bind(&SettingsMenu::graphicOption, this));
  // button->setPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 5, SCREEN_SIZE.y/8));

  // up_mDrawableManager.emplace_back(button);
  // up_mEventHandler.emplace_back(button);

  // button.reset();

  // button = std::make_shared<Button>(m_spAssetsMenager, "Dzwiek");
  // button->setCallBack(std::bind(&SettingsMenu::soundOption, this));
  // button->setPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 3, SCREEN_SIZE.y/8));
  
  // up_mDrawableManager.emplace_back(button);
  // up_mEventHandler.emplace_back(button);

}

