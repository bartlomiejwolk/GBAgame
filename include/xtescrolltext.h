#ifndef XTESCROLLTEXT_H
#define XTESCROLLTEXT_H

#include "gamestate.h"
#include "text.h"
#include "timer.h"


class Xtescrolltext: public IGameState {
 public:
  Xtescrolltext();
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
  Timer* _timer;
  Text* _text;
};



#endif
