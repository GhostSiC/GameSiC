#pragma once

#include <memory>
#include <StartMenuIf.hpp>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>

#include <Button.hpp>
#include <ButtonManager.hpp>

class AssetsMenager;

class StartMenu : public StartMenuIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  StartMenu(std::shared_ptr<AssetsMenager> spAssetsMenager);
  ~StartMenu() = default;

  void initStartMenu();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void poolEvents(sf::Event& event) override;
  bool getActive() override;
  void setActive(bool active) override;

  void startNewGame();
  void exitGame();

private:
  void initButton();
  void handleButtonEvent(Button& button);

  std::shared_ptr<sf::View> m_spView;
  
  std::unique_ptr<std::vector<Button>> m_upButtons;
  std::shared_ptr<AssetsMenager> m_spAssetsMenager;
  bool isActive;
  
};