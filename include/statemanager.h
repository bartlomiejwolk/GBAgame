#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "gamestate.h"

using namespace std;

/*! StateManager */
class StateManager {

 private:
  //! The stack of states.
  vector<IGameState*>* states;

 public:
  //! Constructor
  StateManager();
  //! Destructor
  ~StateManager();  
  //! Remove the current state from the stack and add a new state to the end of the stack.
  /*! 
    \param state IGameState obj.
    \sa PushState(), PopState()
   */
  void ChangeState(IGameState* state); 
  //! Pause the current state and go to a new state.
  /*! 
    \param state state to put on stack
    \sa ChangeState(), PopState()
   */
  void PushState(IGameState* state); 
  //! Leave current state and go to previous state.
  void PopState(); 
  //! Remove current state from states vector.
  void Clear();
  //! Return pointer to states vector
  vector<IGameState*>* ReturnStates() {
    return states;
  }

};

#endif
