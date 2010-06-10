#include "titlescreen.h"

TitleScreen::TitleScreen(StateManager* state, Xtewritebyletter* xtewritebyletter): _option1("xte_writeby_letter",&_timer1) {
  _stateManager = state;
  _xtewritebyletter = xtewritebyletter;
}

void TitleScreen::Init(){
  // show menu <<Init() will be called by StateManager::change_state()>>
  //  _option1.xte_scroll_text();

  tte_write("#{X:16;}xte_writeby_letter\nxte_write_delayed\nxte_writeby_human\nxte_scroll_text");
}

void TitleScreen::CleanUp(){

}

void TitleScreen::HandleEvents(){
  // if button a then changestate to xte_scroll_text()
  if (key_hit(KEY_A))
    _stateManager->change_state(_xtewritebyletter);

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
	  /*      case 2:     _stateManager->change_state(&xtewritebyhuman);
	break;
      case 3:     _stateManager->change_state(&xtescrolltext);
      break;*/
    }
}

void TitleScreen::Update(){

}

void TitleScreen::Display(){

}
