#ifndef XTEWRITEBYLETTER_H
#define XTEWRITEBYLETTER_H

#include "gamestate.h"
#include "text.h"
#include "timer.h"
#include <tonc.h>

class Xtewritebyletter: public IGameState {
 public:
  Xtewritebyletter();
  //! Initialize state
  void Init();
  //! Finish current state
  void CleanUp();
  //! Handle user input
  void HandleEvents();
  //! Update variables
  void Update();
  //! Display on screen
  void Display();
  
 private:
  Text* _text;
};



#endif
