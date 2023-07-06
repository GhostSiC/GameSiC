#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <StateManagerIf>
#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>

class StateManager : public StateManagerIf
{
public:
  StateManager();
  ~StateManager() = default;

  void addState();
  void getState();

  void setDrawState();
  void getDrawState();

  void setEventState();
  void getEventState();

  void deleteState();


private:

  std::vector<std::shared_ptr<DrawableManagerIf>> sp_mDrawable;
  std::vector<std::shared_ptr<EventHandlerIf>> sp_mPoolEvents;



};