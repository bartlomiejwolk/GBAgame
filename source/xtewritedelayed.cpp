#include "xtewritedelayed.h"
#include "statemanager.h"
#include "titlescreen.h"

extern StateManager stateManager;
extern TitleScreen titleScreen;

Xtewritedelayed::Xtewritedelayed(){
  _timer = new Timer;
  _text = new Text(" This is xte_write_delayed() demo.\nEach character is written after the same time periods.",_timer);
}

void Xtewritedelayed::Init(){
  // reset str pointer to 0
  _text->str = _text->firstChar;
  
  // erase screen and reset cursor
  tte_write("#{er:0,0,259,159;}#{Pr}");
}

void Xtewritedelayed::CleanUp(){

}

void Xtewritedelayed::HandleEvents(){
    if(key_hit(KEY_B))
    stateManager.change_state(&titleScreen);
}

void Xtewritedelayed::Update(){
  _text->xte_write_delayed(20);
  //  tte_write("#{er:0,0,259,159;Pr}ERASED");
}

void Xtewritedelayed::Display(){

}
