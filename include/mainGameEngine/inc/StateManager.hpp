#pragma once

#include <memory>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

#include <StateManagerIf.hpp>
#include <DrawableManagerIf.hpp>
#include <EventHandlerIf.hpp>

#include "StateConst.hpp"

class StateManager : public StateManagerIf
{
public:
  StateManager(StateOfGame stateOfGame);
  ~StateManager() override = default;

  StateManager(StateManager&& ) = delete;
  StateManager(const StateManager& ) = delete;
  StateManager& operator=(const StateManager& ) = delete;
  StateManager& operator=(StateManager&& ) = delete;

  void addState(StateOfGame&& stateOfGame) override;
  std::stack<StateOfGame> getState() override;

  StateOfGame top() override;
  void pop() override;

  void deleteState() override;

private:

  std::stack<StateOfGame> m_stateOfGame; 

  //isActive()


};