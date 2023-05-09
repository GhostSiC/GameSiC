
#include <MainEngine.hpp>

#include <City.hpp>

#include <iostream>

class testIf
{
  public:
  virtual void func() const = 0;
};

class AAAAf
{
  public:
  virtual void AAAAAf() const = 0;
};

class test : public testIf, public AAAAf
{
  public:
  test(int a) : a(a) { std::cout << "test()\n"; };
  ~test(){ std::cout << "~test()\n"; };
  void func() const override { std::cout << "testIf(): " << a << std::endl; };
  void AAAAAf() const override { std::cout << "AAAAAf(): " << a << std::endl; };
  std::unique_ptr<int> b;
  int a;
};

MainEngine::MainEngine() :
  isActive{true}
{
  // std::shared_ptr<AAAAf> tes_2;
  // {
  // std::shared_ptr<test> tes = std::make_shared<test>(3);
  // tes_2 = tes;
  // tes->func();
  // }
  
  // tes_2->AAAAAf();

  m_spWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "SFML window");
  m_spView = std::make_shared<sf::View>(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));

  m_spWindow->setView(*m_spView);



}

void MainEngine::initEngine()
{
  sp_mMenu = std::make_shared<Menu>();
  sp_mStartMenu = std::make_shared<StartMenu>();
  sp_mMenu->initMenu();
  sp_mMenu->setActive(true);

  sp_mDrawable.emplace_back(sp_mMenu);
  sp_mDrawable.emplace_back(sp_mStartMenu);


  shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(2000.f, 2000.f));
  
  shape->setFillColor(sf::Color(75,0,130));
  
  mainLoop();
}

void MainEngine::mainLoop()
{
  while (m_spWindow->isOpen())
  {
    poolEvents();

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

void MainEngine::poolEvents()
{
  sf::Event event;
  while (m_spWindow->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      m_spWindow->close();
    if(event.type == sf::Event::MouseButtonPressed)
      std::cout << "AAAAAAAAAAAA\n";
  }
}

// void MainEngine::PushState(std::shared_ptr<StateManagerIf>& state)
// {
//   sp_currentlyState = state;
//   sp_gameState.emplace_back(state);
//   //sp_currentlyState->test();
// }