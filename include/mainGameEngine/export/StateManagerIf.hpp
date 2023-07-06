#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>


class StateManagerIf
{
public:
  virtual ~StateManagerIf() = default;

  virtual void addState() = 0;
  virtual void getState() = 0;

  virtual void setDrawState() = 0;
  virtual void getDrawState() = 0;

  virtual void setEventState() = 0;
  virtual void getEventState() = 0;

  virtual void deleteState() = 0;

protected:
  StateManagerIf(StateManagerIf&& ) = delete;
  StateManagerIf(const StateManagerIf& ) = delete;
  StateManagerIf& operator=(const StateManagerIf& ) = delete;
  StateManagerIf& operator=(StateManagerIf&& ) = delete;

// private:

//   std::vector<std::shared_ptr<DrawableManagerIf>> sp_mDrawable;
//   std::vector<std::shared_ptr<EventHandlerIf>> sp_mPoolEvents;

};