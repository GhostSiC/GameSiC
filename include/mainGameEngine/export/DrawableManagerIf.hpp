#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

//TO DO: podziel to na 2, Update oraz Draw

class DrawableManagerIf
{
public:
    // virtual void Update() = 0;
    // virtual void Draw() = 0;

  //virtual void getState();

  // void push(std::shared_ptr<sf::Drawable> drawable)
  // {
  //   sp_mDrawable.emplace_back(drawable);
  // }

  // std::vector<std::shared_ptr<sf::Drawable>> retVector() const 
  // {
  //   return sp_mDrawable;
  // }


  // std::vector<std::shared_ptr<sf::Drawable>> sp_mDrawable;
  //bool active{true};

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
  virtual bool getActive() = 0;
  virtual void setActive(bool active) = 0;

};