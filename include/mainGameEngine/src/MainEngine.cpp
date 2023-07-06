#include <MainEngine.hpp>

#include <Menu.hpp>
#include <StartMenu.hpp>
#include <AssetsMenager.hpp>

#include <iostream>

class testIf
{
  public:
  virtual void func() const = 0;
};

class AAAAf
{
  public:
  int AAAAAf(){ return 3; };

  private:
  int* ptr = new int(53);
};

class test
{
  public:
  test(std::shared_ptr<AAAAf> af) {  aaaaf = af; b = aaaaf->AAAAAf(); };
  ~test(){ std::cout << "~test()\n"; };

  void print() { std::cout << b << '\n'; }
  //void func() const override { std::cout << "testIf(): " << a << std::endl; };
  //void AAAAAf() const override { std::cout << "AAAAAf(): " << a << std::endl; };
  int b;
  std::shared_ptr<AAAAf> aaaaf;
};

MainEngine::MainEngine() :
  isActive{true}
{

  m_spWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "SFML window");
  m_spView = std::make_shared<sf::View>(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));

  m_texture = std::make_unique<sf::Texture>();

  m_spAssetsMenager = std::make_shared<AssetsMenager>();
  sp_mMenu = std::make_shared<Menu>();
  sp_mStartMenu = std::make_shared<StartMenu>(m_spAssetsMenager);
  sp_mStateGame = std::make_shared<StateOfGame>(StateOfGame::MainMenu);

  m_spWindow->setView(*m_spView);
}

void MainEngine::initEngine()
{

  sp_mMenu->initMenu();
  
  sp_mDrawable.emplace_back(sp_mMenu);
  sp_mDrawable.emplace_back(sp_mStartMenu);
  sp_mPoolEvents.emplace_back(sp_mStartMenu);


  shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(2000.f, 2000.f));
  
  shape->setFillColor(sf::Color(75,0,130));
  
  mainLoop();
}

void MainEngine::mainLoop()
{
  sf::Event event;
  while (m_spWindow->isOpen())
  {
    stateGame();
    poolEvents(event);

    draw(*m_spWindow, sf::RenderStates::Default);
  }
}

void MainEngine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

  m_spWindow->clear();

  target.draw(*shape);
  
  for(const auto& drawable : sp_mDrawable)
  {
    if(drawable->getActive())
    {
      drawable->draw(target, sf::RenderStates::Default);
    }
  }

  m_spWindow->display();
}

bool MainEngine::getActive()
{
  return true;
}

void MainEngine::setActive(bool active)
{
  isActive = active;
}

void MainEngine::poolEvents(sf::Event& event)
{
  while (m_spWindow->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      m_spWindow->close();

    for(const auto& poolEvent : sp_mPoolEvents)
    {
      if(poolEvent->getActive())
      {
        poolEvent->poolEvents(event);
      }
    }

  }
}

void MainEngine::stateGame()
{
  sp_mStartMenu->setActive(true);


}

// void MainEngine::PushState(std::shared_ptr<StateManagerIf>& state)
// {
//   sp_currentlyState = state;
//   sp_gameState.emplace_back(state);
//   //sp_currentlyState->test();
// }