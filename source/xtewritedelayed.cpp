#include "xtewritedelayed.h"

Xtewritedelayed::Xtewritedelayed(){
  _timer = new Timer;
  _text = new Text(" This is xte_write_delayed() demo.\nEach character is written after the same time periods.",_timer);
}

void Xtewritedelayed::Init(){
  tte_write("#{er:0,0,259,159;}#{Pr}");
}

void Xtewritedelayed::CleanUp(){

}

void Xtewritedelayed::HandleEvents(){

}

void Xtewritedelayed::Update(){
  _text->xte_write_delayed(20);
  //  tte_write("#{er:0,0,259,159;Pr}ERASED");
}

void Xtewritedelayed::Display(){

}
