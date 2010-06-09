#include "statemanager.h"

StateManager::StateManager() {
  // Initialize _pstates.
  _pstates = new vector<IGameState*>;

}
StateManager::~StateManager() {

}

void StateManager::change_state(IGameState* state) {
  // Clean up the current state.
   if (!_pstates->empty()) {
      _pstates->back()->CleanUp(); // let the current state to end properly
      _pstates->pop_back();
  }
  // Store and init the new state.
  _pstates->push_back(state);
  _pstates->back()->Init(); 
};

