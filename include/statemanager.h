#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "gamestate.h"

using namespace std;

/*! StateManager */
class StateManager {

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
  void change_state(IGameState* state); 
  //! Pause the current state and go to a new state.
  /*! 
    \param state state to put on stack
    \sa ChangeState(), PopState()
   */
  void push_state(IGameState* state); 
  //! Leave current state and go to previous state.
  void pop_state(); 
  //! Remove current state from states vector.
  void clear();
  //! Return pointer to states vector
  vector<IGameState*>* ReturnStates() {
    return _pstates;
  }
 
   private:
  //! The stack of states.
  vector<IGameState*>* _pstates;
};

#endif
