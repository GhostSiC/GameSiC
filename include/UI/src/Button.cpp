
#include <Button.hpp>

#include <AssetsMenagerIf.hpp>

#include <iostream>

Button::Button(std::shared_ptr<AssetsMenagerIf> assetsMenager) :
  m_drawableStatus{true},
  m_eventStatus{true},
  isActiveAction{true},
  m_spAssetsMenager{assetsMenager}
{
  m_upBackground = std::make_shared<sf::Sprite>();
  m_upFont = std::make_shared<sf::Font>();

  m_text = std::make_shared<sf::Text>();

  std::cout << "create button\n";
}

Button::~Button()
{
  std::cout << "delete button\n";
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if(m_drawableStatus)
  {
    target.draw(*m_upBackground);
    target.draw(*m_text);
  }
}


void Button::setFont(std::shared_ptr<sf::Font> font)
{
  m_text->setFont(*font);
}

void Button::setTexture(std::shared_ptr<sf::Texture> texture)
{
  m_upBackground->setTexture(*texture);
}

void Button::setTextureRect(const sf::IntRect& intRect)
{
  m_upBackground->setTextureRect(intRect);
}

void Button::poolEvents(sf::Event &event)
{
  if(isActiveAction)
  {
  sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
    if (getGlobalBounds().contains(mousePosition))
    {
      m_fCallBack();
    }
  }
}

void Button::setCallBack(std::function<void()> callback)
{
  m_fCallBack = callback;
}

sf::FloatRect Button::getGlobalBounds() const
{
  return m_upBackground->getGlobalBounds();
}

void Button::setText(const std::string& text)
{
  m_text->setString(text);
  centerText();
}

void Button::setSize()
{
}

void Button::setScale(const sf::Vector2f& scale)
{
  m_upBackground->setScale(scale);
}

void Button::setFontSize(sf::Vector2f scale)
{
  m_text->setScale(scale);
}

void Button::setFontColor(sf::Color color)
{
  m_text->setFillColor(color);
}

bool Button::getDrawableStatus()
{
  return m_drawableStatus;
}

void Button::setDrawableStatus(bool status)
{
  m_drawableStatus = status;
}

bool Button::getEventStatus()
{
  return m_eventStatus;
}

void Button::setEventStatus(bool status)
{
  m_eventStatus = status;
}

bool Button::getActiveAction()
{
  return isActiveAction;
}

void Button::setActiveAction(bool active)
{
  isActiveAction = active;
}

void Button::setOrigin()
{
  m_text->setOrigin(sf::Vector2f(m_text->getGlobalBounds().left/2, m_text->getGlobalBounds().height/2));
  m_upBackground->setOrigin(sf::Vector2f(m_upBackground->getTextureRect().width/2, m_upBackground->getTextureRect().height/2));
}

void Button::setPosition(const sf::Vector2f& position)
{
  //setOrigin();
  m_upBackground->setOrigin(sf::Vector2f(m_upBackground->getTextureRect().width/2, m_upBackground->getTextureRect().height/2));
  //m_text->setPosition(sf::Vector2f(SCREEN_SIZE.x/2 - (m_text->getGlobalBounds().width/2), SCREEN_SIZE.y/5));
  m_upBackground->setPosition(position);

  centerText();
}

// TODO: zastanow sie jak zrobic text oraz ustawic go na srodek ekranu
void Button::centerText()
{
  auto position{m_upBackground->getPosition()};
  sf::FloatRect textBounds = m_text->getLocalBounds();
  //std::cout << "Text size: " << textBounds.width << " x " << textBounds.height << std::endl;

  //m_text->setOrigin(sf::Vector2f(m_text->getGlobalBounds().left/2, m_text->getGlobalBounds().height/2));
  m_text->setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
  m_text->setPosition(position);


  //m_text->setPosition(sf::Vector2f(SCREEN_SIZE.x/2 - (m_text->getGlobalBounds().width/2), SCREEN_SIZE.y/5));
}