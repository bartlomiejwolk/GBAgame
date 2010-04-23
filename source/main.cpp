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

  game.init();

  // Set initial state
  stateManager.change_state(&titleScreen);

  // Move to GameEngine::init

  REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;
  
  tte_init_se(
	      0,                      // Background number (BG 0)
	      BG_CBB(0)|BG_SBB(31)|BG_REG_32x32,   // BG control (for REG_BGxCNT)
	      0,                      // Tile offset (special cattr)
	      CLR_YELLOW,             // Ink color
	      14,                     // BitUnpack offset (on-pixel = 15)
	      NULL,                   // Default font (sys8) 
	      NULL);                  // Default renderer (se_drawg_s)

  pal_bg_bank[0][1]= CLR_YELLOW;
  
  // ^^^ Move to GameEngine::init()

  Timer timer;
  Text text("Sunrise,\n sunset,\n sunrise,\n sunset...\n goes\n the\n song\n of\n the\n Fidler\n on\n the\n Roof.\n You\n can\n almost\n see\n the\n journey\n of\n the\n sun\n as\n it\n moves\n fom\n one\n horizon\n (the floor)\n to\n its\n noonday\n heights\n in\n the\n sky\n overhead\n (ceiling)\n and\n then\n disappears\n over\n the\n other\n horizon\n - day\n ofter\n day\n marking\n the\n span\n of\n our\n lives.\n");
  
  // screen position
  int y = 0;
  // contain y coordinate
  char scroll_value[20];

  // print some text
  //tte_write("aaaa aaa");
  tte_write("#{P:32,32}Also available in 8x16");

  while (1) {
    vid_vsync();
    key_poll();
    game.update_seed();

    // scroll bg
    //    y += key_tri_vert();
    if (timer.frame(5))
      if (key_is_down(KEY_DOWN)) {
	y--;
	REG_BG0VOFS = y;
      }

    // reset y
    //    if (y == 32*8)
    if (y == -30) {
      y = 0;
    }
    // display some text
    sprintf(scroll_value, "#{P:0,0}%d   ", y);
    //if (key_tri_vert())
    tte_write(scroll_value);

    game.handle_events(&stateManager);
    game.update();
    game.draw();
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
