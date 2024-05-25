#pragma once

#include <ButtonBuilderIf.hpp>

#include <memory>
#include <functional>

#include <Button.hpp>

class AssetsMenagerIf;

class StandardButtonBuilder : public ButtonBuilderIf
{
public:
  StandardButtonBuilder(std::shared_ptr<AssetsMenagerIf> assetsMenager);
  ~StandardButtonBuilder() = default;

  std::shared_ptr<Button> build() override;
  void reset() override;

  StandardButtonBuilder& initText(std::string&& text) override;
  StandardButtonBuilder& initFont(std::shared_ptr<sf::Font> font) override;
  StandardButtonBuilder& initFontSize(sf::Vector2f&& scale) override;
  StandardButtonBuilder& initFontColor(sf::Color color) override;
  
  StandardButtonBuilder& initScale(sf::Vector2f&&) override;
  StandardButtonBuilder& initPosition(sf::Vector2f&&) override;

  StandardButtonBuilder& initTexture(std::shared_ptr<sf::Texture> texture, sf::IntRect&& intRect) override;

  StandardButtonBuilder& initCallBack(std::function<void()> callback) override;
  StandardButtonBuilder& initActiveAction(bool active) override;


private:

  std::shared_ptr<AssetsMenagerIf> m_spAssetsMenager;

  //Default value
  std::shared_ptr<sf::Font> m_spDefaultFont;
  std::shared_ptr<sf::Texture> m_spDefaultTexture;

  std::string m_defaultText = ""; // initText
  sf::Vector2f m_defaultFontSize = sf::Vector2f(1,1); // initFontSize
  sf::Color m_defaultColor = sf::Color::White; // initFontColor
  sf::Vector2f m_defaultScale = sf::Vector2f(1,1); // initScale
  sf::Vector2f m_defaultPosition = sf::Vector2f(0,0); // initPosition
  sf::IntRect m_defaultTextureRect = sf::IntRect(0,0,397,97);
  std::function<void()> m_defaultCallback = [](){};
  bool m_defaultActiveAction{true};

  // Current values
  std::shared_ptr<sf::Font> m_spFont{m_spDefaultFont}; // initFont
  std::shared_ptr<sf::Texture> m_texture{m_spDefaultTexture}; // initTexture

  std::string m_text{m_defaultText}; // initText
  sf::Vector2f m_fontSize{m_defaultFontSize}; // initFontSize
  sf::Color m_color{m_defaultColor};// initFontColor
  sf::Vector2f m_scale{m_defaultScale}; // initScale
  sf::Vector2f m_position{m_defaultPosition}; // initPosition
  sf::IntRect m_textureRect{m_defaultTextureRect};
  std::function<void()> m_callback{m_defaultCallback};
  bool m_activeAction{m_defaultActiveAction};
};