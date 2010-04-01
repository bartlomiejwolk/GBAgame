#include <tonc.h>
#include <stdlib.h>

#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h"
#include "text.h"
#include "timer.h"
#include "titlescreen.h"

int main() {

  GameEngine game;
  TitleScreen titleScreen;
  StateManager stateManager;

  game.Init();

  // Set initial state
  stateManager.change_state(&titleScreen);

  // Move to GameEngine::init
  REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;
  
  tte_init_se(
	      0,                      // Background number (BG 0)
	      BG_CBB(0)|BG_SBB(31)|BG_REG_32x64,   // BG control (for REG_BGxCNT)
	      0,                      // Tile offset (special cattr)
	      CLR_YELLOW,             // Ink color
	      14,                     // BitUnpack offset (on-pixel = 15)
	      NULL,                   // Default font (sys8) 
	      NULL);                  // Default renderer (se_drawg_s)
  
  pal_bg_bank[0][1]= CLR_YELLOW;
  // ^^^ Move to GameEngine::init()

  Timer timer(8,10,11,20,30);
  Text text("\nSome text to display, written by human.", &timer);
  
  while (1) {
    vid_vsync();
    key_poll();
    game.update_seed();

    text.xte_writeby_human();

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
pp
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
