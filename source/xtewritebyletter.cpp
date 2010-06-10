#include "xtewritebyletter.h"

Xtewritebyletter::Xtewritebyletter() : _text("This is demo for xte_writeby_letter() method.\nEach character is displayed in consequent frame") {

}

void Xtewritebyletter::Init(){
  // clear screen
  tte_write("#{er:0,0,239,159}");
  tte_write("#{P;}");
}

void Xtewritebyletter::CleanUp(){

}

void Xtewritebyletter::HandleEvents(){

}

void Xtewritebyletter::Update(){
  
  _text.xte_writeby_letter();

}

void Xtewritebyletter::Display(){

}
