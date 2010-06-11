#include "xtewritebyletter.h"
#include "statemanager.h"
#include "titlescreen.h"

extern StateManager stateManager;
extern TitleScreen titleScreen;

Xtewritebyletter::Xtewritebyletter() {
_text = new Text(" This is demo for xte_writeby_letter() method.\nEach character is displayed in consequent frame");
}

void Xtewritebyletter::Init(){
  // reset str pointer to 0
  _text->str = _text->firstChar;

  // clear screen
  tte_write("#{er:0,0,239,159}");
  tte_write("#{P;}");
}

void Xtewritebyletter::CleanUp(){

}

void Xtewritebyletter::HandleEvents(){
  if(key_hit(KEY_B))
    stateManager.change_state(&titleScreen);
}

void Xtewritebyletter::Update(){
  _text->xte_writeby_letter();
}

void Xtewritebyletter::Display(){

}
