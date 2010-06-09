#ifndef XTEWRITEBYHUMAN_H
#define XTEWRITEBYHUMAN_H

#include "gamestate.h"

class Xtewritebyhuman: public IGameState {
 public:
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

};



#endif
