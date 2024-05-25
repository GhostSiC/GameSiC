#include "StateManager.hpp"

StateManager::StateManager(StateOfGame stateOfGame)
{
    m_stateOfGame.push(stateOfGame);
}

void StateManager::addState(StateOfGame&& stateOfGame)
{
    m_stateOfGame.push(stateOfGame);
}

std::stack<StateOfGame> StateManager::getState()
{
    return m_stateOfGame;
}

StateOfGame StateManager::top()
{
    return m_stateOfGame.top();
}

void StateManager::pop()
{
    m_stateOfGame.pop();
}

// TODO: zrobic cos z tym?
void StateManager::deleteState()
{
    //m_stateOfGame;
}
