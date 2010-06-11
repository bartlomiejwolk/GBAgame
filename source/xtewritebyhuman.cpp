#include "xtewritebyhuman.h"

extern TitleScreen titleScreen;
extern StateManager stateManager;

Xtewritebyhuman::Xtewritebyhuman() {
  _timer = new Timer(2,5,7,13,30);
  _text = new Text(" Text displayed with xte_writeby_human. Each character shows in diffrent intervals of time",_timer);
}

void Xtewritebyhuman::Init(){
  // reset str pointer to 0
  _text->str = _text->firstChar;

  tte_write("#{er:0,0,249,159;Pr}");

}

void Xtewritebyhuman::CleanUp(){

}

void Xtewritebyhuman::HandleEvents(){
  if(key_hit(KEY_B))
    stateManager.change_state(&titleScreen);
}

void Xtewritebyhuman::Update(){
    _text->xte_writeby_human();
  //  _text->xte_write_delayed(23);
}

void Xtewritebyhuman::Display(){

}
