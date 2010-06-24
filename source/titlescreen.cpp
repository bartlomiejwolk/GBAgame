#include "titlescreen.h"
#include "xtescrolltext.h"

extern Xtewritedelayed xtewritedelayed;
extern Xtewritebyhuman xtewritebyhuman;
extern Xtescrolltext xtescrolltext;

TitleScreen::TitleScreen(StateManager* state, Xtewritebyletter* xtewritebyletter): _option1("xte_writeby_letter",&_timer1) {
  _stateManager = state;
  _xtewritebyletter = xtewritebyletter;
}

void TitleScreen::Init(){
  REG_BG0VOFS = 0;

  tte_write("#{er:0,0,249,159;X:16;Pr}  xte_writeby_letter\nxte_write_delayed\nxte_writeby_human\nxte_scroll_text");
}

void TitleScreen::CleanUp(){

}

void TitleScreen::HandleEvents(){
  // moving through the menu
  if (key_hit(KEY_DOWN))
    if (menuIndex != 3)
      menuIndex++;

  if (key_hit(KEY_UP))
    if (menuIndex != 0)
      menuIndex--;

  if (key_hit(KEY_A))
    switch (menuIndex) {
    case 0:     _stateManager->change_state(_xtewritebyletter);
      break;
    case 1:     _stateManager->change_state(&xtewritedelayed);
      break;
    case 2:     _stateManager->change_state(&xtewritebyhuman);
      break;
    case 3:     _stateManager->change_state(&xtescrolltext);
      break;
    }

  if (key_hit(KEY_ANY))
    switch (menuIndex) {
    case 0: tte_write("#{P;es}  xte_writeby_letter\nxte_write_delayed\nxte_writeby_human\nxte_scroll_text");
      break;
    case 1: tte_write("#{P;es}xte_writeby_letter\n  xte_write_delayed\nxte_writeby_human\nxte_scroll_text");
      break;
    case 2: tte_write("#{P;es}xte_writeby_letter\nxte_write_delayed\n  xte_writeby_human\nxte_scroll_text");
      break;
    case 3: tte_write("#{P;es}xte_writeby_letter\nxte_write_delayed\nxte_writeby_human\n  xte_scroll_text");
      break;
    }
}

void TitleScreen::Update(){

}

void TitleScreen::Display(){

}
