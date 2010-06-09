#ifndef XTESCROLLTEXT_H
#define XTESCROLLTEXT_H

#include "gamestate.h"

class Xtescrolltext: public IGameState {
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
