#pragma once

#include <ButtonIf.hpp>

#include <memory>
#include <functional>

#include <SFML/Graphics.hpp>

#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>
#include <ButtonManager.hpp>

class Button : public ButtonIf, public DrawableManagerIf, public EventHandlerIf
{
public:
  Button(TypeButton&& typeOfButton = TypeButton::NONE , std::string&& text = "");
  ~Button() = default;


  // ButtonIf
  void setText() override;
  void setSize() override;
  void setScale(int scale) override;
  void setFontSize() override;

  bool getActive() override;
  void setActive(bool active) override;
  // DrawableManagerIf
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  // EventHandlerIf
  //void poolEvents() override;

  void setFont(std::shared_ptr<sf::Font> font);
  void setTexture(std::shared_ptr<sf::Texture> texture);
  void setTexture(std::string&& text);


  void poolEvents(sf::Event& event) override;
  void setCallBack(std::function<void()>);

  // Sprite
  sf::FloatRect getGlobalBounds() const;

  TypeButton getTypeButton() const;

private:
  bool isActive;

  //std::shared_ptr<AssetsMenager> m_spAssetsMenager;

  void initFonts();
  void setOrigin();
  void setButtonType();

  std::shared_ptr<sf::Font> m_upFont;
  std::shared_ptr<sf::Text> m_text;

  std::shared_ptr<sf::Sprite> m_upBackground;

  TypeButton enTypeOfButton;

  std::function<void()> m_fCallBack;
};