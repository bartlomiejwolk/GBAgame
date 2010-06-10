#ifndef XTEWRITEDELAYED_H
#define XTEWRITEDELAYED_H

#include "gamestate.h"
#include "text.h"
#include <tonc.h>

class Xtewritedelayed: public IGameState {
 public:
  Xtewritedelayed();
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
  Timer* _timer;
};



#endif
