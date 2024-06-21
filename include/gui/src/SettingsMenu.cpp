
#include <SettingsMenu.hpp>

#include <SFML/Graphics.hpp>

#include <AssetsMenager.hpp>
#include <Button.hpp>
#include <StateConst.hpp>
#include <StateManager.hpp>
#include <StateManagerIf.hpp>
#include <SettingsAdvance.hpp>
#include <StandardButtonBuilder.hpp>

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
    graphicButtons->setActiveAction(1);
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
  StandardButtonBuilder builder{m_spAssetsMenager};

  std::shared_ptr<Button> button = builder
    .initText("Powrot")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/8, SCREEN_SIZE.y/8))
    .initCallBack(std::bind(&SettingsMenu::backOption, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Grafika")
    .initPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 5, SCREEN_SIZE.y/8))
    .initCallBack(std::bind(&SettingsMenu::graphicOption, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("Dzwiek")
    .initPosition(sf::Vector2f((SCREEN_SIZE.x/8) * 3, SCREEN_SIZE.y/8))
    .initCallBack(std::bind(&SettingsMenu::soundOption, this))
    .build();

  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);
}

void SettingsMenu::initGraphicButton()
{
  StandardButtonBuilder builder{m_spAssetsMenager};

  std::shared_ptr<Button> button = builder
    .initText("resolution")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/2, SCREEN_SIZE.y/2))
    .initCallBack(std::bind(&SettingsAdvance::changeResolution, m_spSettingsAdvance))
    .initActiveAction(false)
    .build();

  m_upGraphicButtons.push_back(button);
  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);

  button = builder
    .initText("apply")
    .initPosition(sf::Vector2f(SCREEN_SIZE.x/2, SCREEN_SIZE.y/3 * 2))
    .initCallBack(std::bind(&SettingsAdvance::changeResolution, m_spSettingsAdvance))
    .initActiveAction(false)
    .build();

  m_upGraphicButtons.push_back(button);
  up_mDrawableManager.emplace_back(button);
  up_mEventHandler.emplace_back(button);
}
