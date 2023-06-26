
#include <Button.hpp>

#include <iostream>

namespace
{

}

Button::Button(TypeButton&& typeOfButton, std::string&& text) :
  isActive{false}, enTypeOfButton{typeOfButton}
{
  m_upBackground = std::make_shared<sf::Sprite>();
  m_upFont = std::make_shared<sf::Font>();

  m_text = std::make_shared<sf::Text>();

  initFonts();
}


void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if(isActive)
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

void Button::setTexture(std::string &&text)
{
  m_text->setString(text);
}

void Button::setText()
{
}

void Button::setSize()
{
}

void Button::setScale(int scale)
{
  m_upBackground->setScale(3,1);

}

void Button::setFontSize()
{
}

void Button::initFonts()
{
  m_text->setFont(*m_upFont);
  m_text->setCharacterSize(32);
  m_text->setFillColor(sf::Color::White);
}

void Button::poolEvents()
{
}

bool Button::getActive()
{
  return isActive;
}

void Button::setActive(bool active)
{
  setButtonType();
  isActive = active;
}

void Button::setOrigin()
{
  m_text->setOrigin(sf::Vector2f(m_text->getGlobalBounds().left/2, m_text->getGlobalBounds().height/2));
  m_upBackground->setOrigin(sf::Vector2f(m_upBackground->getTextureRect().width/2, m_upBackground->getTextureRect().height/2));
}

void Button::setButtonType()
{
  switch (enTypeOfButton)
  {
  case TypeButton::StartButton:
    m_upBackground->setTextureRect(sf::IntRect(0,0,397,97));
    m_text->setString("Wejdz do gry");
    setOrigin();
    m_text->setPosition(sf::Vector2f(SCREEN_SIZE.x/2 - (m_text->getGlobalBounds().width/2), SCREEN_SIZE.y/5));
    m_upBackground->setPosition(sf::Vector2f(SCREEN_SIZE.x/2, SCREEN_SIZE.y/5));
    break;

  case TypeButton::ExitButton:
    m_upBackground->setTextureRect(sf::IntRect(0,97,397,97));
    m_text->setString("Wyjdz z gry");
    setOrigin();
    m_text->setPosition(sf::Vector2f(SCREEN_SIZE.x/2 - (m_text->getGlobalBounds().width/2), SCREEN_SIZE.y/5 * 4));
    m_upBackground->setPosition(sf::Vector2f(SCREEN_SIZE.x/2, SCREEN_SIZE.y/5 * 4));
    break;

  default:
    break;
  }
}
