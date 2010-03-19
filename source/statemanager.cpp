#include "statemanager.h"

StateManager::StateManager() {
  // Initialize states.
  states = new vector<IGameState*>;

}
StateManager::~StateManager() {

}

void StateManager::ChangeState(IGameState* state) {
  // Clean up the current state.
   if (!states->empty()) {
      states->back()->CleanUp(); // let the current state to end properly
      states->pop_back();
  }
  // Store and init the new state.
  states->push_back(state);
  states->back()->Init(); 
};
