#include <tonc.h>
#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h"

int main() {

  GameEngine game;
  TitleScreen titleScreen;
  StateManager stateManager;
  
  game.Init();
  // Use StateManager obj. for changing game state to TitleScreen.
  stateManager.ChangeState(&titleScreen);

  while (1) {
    vid_vsync();
    game.HandleEvents(&stateManager);
    game.Update();
    game.Draw();
  }

  return 0;
}

/*
Ver. 0.0.8
> 

Ver. 0.0.7
> Add destructors to each base class
> Change GameState class name to IGameState (interface)

Ver. 0.0.6
> Revert public: and private: accessors order
> Add constructors without args to each base class

Ver. 0.0.5
> StateManager::ChangeState works now.
>.. Remove StateManager::ReturnStates() preserving it's functionality
! states is private filed of StateManager and cannot be accessed from objest that isn't friend
>.. Make GameEngine frient of StateManager class. Then do the task above.

Ver. 0.0.4
> Create a pointer to vector states in StateManger.
> Create StateManager::ReturnStates().
> Add arg typu StateManager* to GameEngine::HandleEvents().
> In GameEngine::HandleEvents() execute HandleEvents() of the current state.
! StateManager::ChangeState doesn't work.

Version 0.0.3
> Added names.txt
> Updated main loop
*/
