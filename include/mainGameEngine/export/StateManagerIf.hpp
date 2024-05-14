#pragma once

#include <memory>
#include <vector>
#include <stack>

enum class StateOfGame : int16_t;

class StateManagerIf
{
public:
  virtual ~StateManagerIf() = default;

  virtual void addState(StateOfGame&&) = 0;

  // Get stack
  virtual std::stack<StateOfGame> getState() = 0;
  
  //Get element on top
  virtual StateOfGame top() = 0;
  
  // Delete element on top
  virtual void pop() = 0;

  virtual void deleteState() = 0;
};