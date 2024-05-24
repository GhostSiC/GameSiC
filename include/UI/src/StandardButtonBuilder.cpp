
#include <StandardButtonBuilder.hpp>

#include <AssetsMenager.hpp>

#include <iostream>

StandardButtonBuilder::StandardButtonBuilder() :
  m_spAssetsMenager{AssetsMenager::getInstance()},
  m_spDefaultFont{m_spAssetsMenager.getBasicFont()},
  m_spDefaultTexture{m_spAssetsMenager.getBasicTexture()}
{
  std::cout << "create StandardButtonBuilder\n";
}

std::shared_ptr<Button> StandardButtonBuilder::build()
{
  std::shared_ptr<Button> button = std::make_shared<Button>();

  button->setTexture(m_spDefaultTexture);
  button->setTextureRect(m_textureRect);
  button->setFont(m_spDefaultFont);

  button->setText(m_text);
  button->setFontSize(m_fontSize);
  button->setFontColor(m_color);
  button->setScale(m_scale);
  button->setPosition(m_position);
  button->setCallBack(m_callback);
  button->setActiveAction(m_activeAction);
  button->setDrawableStatus(m_activeAction);
  button->setEventStatus(m_activeAction);

  reset();
  return button;
}
void StandardButtonBuilder::reset()
{
  m_text = m_defaultText;
  m_fontSize = m_defaultFontSize;
  m_color = m_defaultColor;
  m_scale = m_defaultScale;
  m_position = m_defaultPosition;
  m_textureRect = m_defaultTextureRect;
  m_callback = m_defaultCallback;
  m_activeAction = m_defaultActiveAction;
}

StandardButtonBuilder& StandardButtonBuilder::initFont(std::shared_ptr<sf::Font> font)
{
  m_spFont = font;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initFontColor(sf::Color color)
{
  m_color = color;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initText(std::string&& text)
{
  m_text = text;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initFontSize(sf::Vector2f&& scale)
{
  m_fontSize = scale;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initScale(sf::Vector2f&& scale)
{
  m_scale = scale;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initPosition(sf::Vector2f&& position)
{
  m_position = position;
  return *this;
}

StandardButtonBuilder& StandardButtonBuilder::initTexture(std::shared_ptr<sf::Texture> texture, sf::IntRect&& intRect)
{
  m_texture = texture;
  m_textureRect = intRect;
  return *this;
}

StandardButtonBuilder &StandardButtonBuilder::initCallBack(std::function<void()> callback)
{
    m_callback = callback;
    return *this;
}

StandardButtonBuilder &StandardButtonBuilder::initActiveAction(bool active)
{
  m_activeAction = active;
  return *this;
}
