#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "gamestate.h"
#include "text.h"
#include "timer.h"

/*! Class derivated from IGameState. */
class TitleScreen: public IGameState {
 public:
  TitleScreen();
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
  Text _option1;
  Timer _timer1;
};
#endif
