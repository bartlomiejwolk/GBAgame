#include "titlescreen.h"

TitleScreen::TitleScreen(): _option1("xte_writeby_letter",&_timer1) {

}

void TitleScreen::Init(){
  // show menu <<Init() will be called by StateManager::change_state()>>
  _option1.xte_scroll_text();
}

void TitleScreen::CleanUp(){

}

void TitleScreen::HandleEvents(){

}

void TitleScreen::Update(){

}

void TitleScreen::Display(){

}
