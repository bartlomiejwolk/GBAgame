#include "xtescrolltext.h"
#include "titlescreen.h"
#include "statemanager.h"

extern TitleScreen titleScreen;
extern StateManager stateManager;

Xtescrolltext::Xtescrolltext(){
  _timer = new Timer();
  _text = new Text(" Text displayed with xte_scroll_text. It's like in the movies.\n\nUnfortunately not completed yet.\n\nSunrise,\n sunset,\n sunrise,\n sunset...\n goes\n the\n song\n of\n the\n Fidler\n on\n the\n Roof.\n You\n can\n almost\n see\n the\n journey\n of\n the\n sun\n as\n it\n moves\n rfom\n one\n horizon\n (the floor)\n to\n its\n noonday\n heights\n in\n the\n sky\n overhead\n (ceiling)\n and\n then\n disappears\n over\n the\n other\n horizon\n - day\n ofter\n day\n marking\n the\n span\n of\n our\n lives.\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n b",_timer);
}

void Xtescrolltext::Init(){
  // reset str pointer to 0
  _text->str = _text->firstChar;

  // reset BG position
  _text->y = 11*8;

  // clear screen and reset cursor position
  tte_write("#{er:0,0,249,159;Pr}");

  //  tte_write("tte_scroll_text()");
}

void Xtescrolltext::CleanUp(){

}

void Xtescrolltext::HandleEvents(){
  if(key_hit(KEY_B))
    stateManager.change_state(&titleScreen);
}

void Xtescrolltext::Update(){
  _text->xte_scroll_text();
}

void Xtescrolltext::Display(){

}
