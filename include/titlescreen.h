#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "gamestate.h"
#include "text.h"
#include "timer.h"
#include "statemanager.h"
#include "xtewritebyletter.h"
#include "xtewritedelayed.h"
#include "xtewritebyhuman.h"


/*! Class derivated from IGameState. */
class TitleScreen: public IGameState {
 public:
  TitleScreen(StateManager*, Xtewritebyletter*);
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
  StateManager* _stateManager;
  Text _option1;
  Timer _timer1;
  Xtewritebyletter* _xtewritebyletter;


  // menu index
  uint menuIndex;

};
#endif
