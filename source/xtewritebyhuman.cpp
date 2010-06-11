#include "xtewritebyhuman.h"

Xtewritebyhuman::Xtewritebyhuman() {
  _timer = new Timer(2,5,7,13,30);
  _text = new Text(" Text displayed with xte_writeby_human. Each character shows in diffrent intervals of time",_timer);
}

void Xtewritebyhuman::Init(){
  //    tte_write("#{er:0,0,259,159;Pr}xtewritebyhuman");
  tte_write("#{er:0,0,249,159;Pr}");

}

void Xtewritebyhuman::CleanUp(){

}

void Xtewritebyhuman::HandleEvents(){

}

void Xtewritebyhuman::Update(){
    _text->xte_writeby_human();
  //  _text->xte_write_delayed(23);
}

void Xtewritebyhuman::Display(){

}
