#include "titlescreen.h"

TitleScreen::TitleScreen(StateManager* state): _option1("xte_writeby_letter",&_timer1) {
  _stateManager = state;
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
  //  if (key_hit(KEY_A))
    
}

void TitleScreen::Update(){

}

void TitleScreen::Display(){

}
