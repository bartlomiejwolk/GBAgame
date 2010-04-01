#include "statemanager.h"

StateManager::StateManager() {
  // Initialize _states.
  _states = new vector<IGameState*>;

}
StateManager::~StateManager() {

}

void StateManager::change_state(IGameState* state) {
  // Clean up the current state.
   if (!_states->empty()) {
      _states->back()->CleanUp(); // let the current state to end properly
      _states->pop_back();
  }
  // Store and init the new state.
  _states->push_back(state);
  _states->back()->Init(); 
};
