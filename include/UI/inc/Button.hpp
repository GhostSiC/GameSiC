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
  Button(std::shared_ptr<AssetsMenagerIf> assetsMenager, std::string&& text = "", TypeButton typeButton = TypeButton::NORMAL);
  ~Button();
  //~Button() = default;


  // ButtonIf
  void setText(std::string&& text) override;
  void setSize() override;
  void setScale(int scale) override;
  void setFontSize() override;
  void setOrigin() override;
  void setPosition(sf::Vector2f&& position) override;


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
  void setTextureRect(sf::IntRect&& intRect) override;
  //void setTexture(std::string&& text) override;


  void poolEvents(sf::Event& event) override;
  void setCallBack(std::function<void()>) override;

  // Sprite
  sf::FloatRect getGlobalBounds() const override;

private:
  bool m_drawableStatus;
  bool m_eventStatus;
  bool isActiveAction;

  //std::shared_ptr<AssetsMenager> m_spAssetsMenager;

  void initFonts();
  void initButtonPreSetting(TypeButton typeButton);


  void centerText(sf::Vector2f& position);

  std::shared_ptr<sf::Font> m_upFont;
  std::shared_ptr<sf::Text> m_text;

  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;

  std::shared_ptr<sf::Sprite> m_upBackground;

  std::function<void()> m_fCallBack;
};