#pragma once

//class Vector2f;

class ButtonIf
{
public:
  virtual void setText() = 0;
  virtual void setSize() = 0;
  virtual void setScale(int scale) = 0;
  virtual void setFontSize() = 0;
};