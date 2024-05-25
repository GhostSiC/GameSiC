#pragma once

#include <ButtonIf.hpp>

#include <memory>
#include <functional>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>
#include <StateConst.hpp>

class AssetsMenagerIf;

class Button : public ButtonIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  Button(std::shared_ptr<AssetsMenagerIf> assetsMenager);
  ~Button();
  //~Button() = default;


  // ButtonIf
  void setText(const std::string& text) override;
  void setSize() override;
  void setScale(const sf::Vector2f& scale) override;
  void setFontSize(sf::Vector2f scale) override;
  void setFontColor(sf::Color color) override;
  void setOrigin() override;
  void setPosition(const sf::Vector2f& position) override;


  bool getDrawableStatus() override;
  void setDrawableStatus(bool status) override;
  bool getEventStatus() override;
  void setEventStatus(bool status) override;

  bool getActiveAction() override;
  void setActiveAction(bool active) override;
  // DrawableManagerIf
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  // EventHandlerIf
  //void poolEvents() override;

  void setFont(std::shared_ptr<sf::Font> font) override;
  void setTexture(std::shared_ptr<sf::Texture> texture) override;
  void setTextureRect(const sf::IntRect& intRect) override;
  //void setTexture(std::string&& text) override;


  void poolEvents(sf::Event& event) override;
  void setCallBack(std::function<void()>) override;

  // Sprite
  sf::FloatRect getGlobalBounds() const override;

private:
  bool m_drawableStatus;
  bool m_eventStatus;
  bool isActiveAction;

  void centerText();

  std::shared_ptr<sf::Font> m_upFont;
  std::shared_ptr<sf::Text> m_text;

  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;

  std::shared_ptr<sf::Sprite> m_upBackground;

  std::function<void()> m_fCallBack;
};