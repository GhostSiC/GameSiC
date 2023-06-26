#pragma once

#include <memory>
#include <StartMenuIf.hpp>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <PoolEventsIf.hpp>

#include <Button.hpp>

class AssetsMenager;

class StartMenu : public StartMenuIf, public DrawableManagerIf, public PoolEventsIf
{
public:
  StartMenu(std::shared_ptr<AssetsMenager> spAssetsMenager);
  ~StartMenu() = default;

  // virtual EngineIf() = 0;
  // virtual ~MainEngineIf() = 0;
  void initStartMenu();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void poolEvents() override;
  bool getActive() override;
  void setActive(bool active) override;

  //void getState() override;


  // void addState();
  // void removeState();

  // void Update() override;
  // void Draw() override;
private:
  //std::shared_ptr<sf::RenderWindow> m_spWindow;
  std::shared_ptr<sf::View> m_spView;
  
  std::unique_ptr<std::vector<Button>> m_upStartButton;
  std::shared_ptr<AssetsMenager> m_spAssetsMenager;
  bool isActive;
  
};