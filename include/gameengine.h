#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <tonc.h>
#include "gamestate.h"
#include "statemanager.h"
// --- Testing update_seed() ---
#include "timer.h"
// ^^^ tus

/*! GameEngine */
class GameEngine {

 private:
  // --- update_seed() ---

  //! Value that is currently used for seeding srand()
  int _seedCurr;
  //! Previously used value for seeding srand()
  int _seedPrev;
  Timer _timer;

 public:
  //! Constructor
  GameEngine();
  //! Destructor
  ~GameEngine();
  //! Init
  void init();
  //! Operate on StateManager class object
  void handle_events(StateManager*);
  //! Update variables
  void update();
  //! Draw on screen
  void draw();
  //! Update _seedCurr variable for srand(). The seed value depend on pressed button and curFrame value at that time. Place it in main while().
  void update_seed();

};

#endif
