#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "gamestate.h"

/*! Class derivated from IGameState. */
class TitleScreen: public IGameState {
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
