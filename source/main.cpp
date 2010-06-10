#include <tonc.h>
#include <stdlib.h>

#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h"
#include "text.h"
#include "timer.h"
#include "titlescreen.h"
#include "xtewritebyletter.h"
#include "xtewritedelayed.h"

Xtewritedelayed xtewritedelayed;

int main() {

  irq_init(NULL);
  irq_add(II_VBLANK, NULL);

  GameEngine game;
  StateManager stateManager;
  Xtewritebyletter xtewritebyletter;



  TitleScreen titleScreen(&stateManager, &xtewritebyletter);

  REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;
  
  // All text states uses this one initializer
  tte_init_se(
	      0,                      // Background number (BG 0)
	      BG_CBB(0)|BG_SBB(31)|BG_REG_32x32,   // BG control (for REG_BGxCNT)
	      0,                      // Tile offset (special cattr)
	      CLR_YELLOW,             // Ink color
	      14,                     // BitUnpack offset (on-pixel = 15)
	      NULL,                   // Default font (sys8) 
	      NULL);                  // Default renderer (se_drawg_s)

  // set text color
  pal_bg_bank[0][1]= CLR_YELLOW;

  // set initial state

  stateManager.change_state(&titleScreen);

  
    Timer timer;
    CSTR string = " Sunrise,\n sunset,\n sunrise,\n sunset...\n goes\n the\n song\n of\n the\n Fidler\n on\n the\n Roof.\n You\n can\n almost\n see\n the\n journey\n of\n the\n sun\n as\n it\n moves\n rfom\n one\n horizon\n (the floor)\n to\n its\n noonday\n heights\n in\n the\n sky\n overhead\n (ceiling)\n and\n then\n disappears\n over\n the\n other\n horizon\n - day\n ofter\n day\n marking\n the\n span\n of\n our\n lives.\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n b";
  Text text(string,&timer);
  
  while (1) {
    vid_vsync();
    key_poll();
    game.update_seed();

    //    text.xte_scroll_text();

    game.handle_events(&stateManager);
    game.update(&stateManager);
  }
  return 0;
}
