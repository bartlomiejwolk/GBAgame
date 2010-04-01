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

  //! Store amount of frames that have passed from the beginning of the game. Used in update_seed().
  uint _frameCurr;
  // these two were moved from public:
  //! Value that is currently used for seeding srand()
  int _seedCurr;
  //! Previously used value for seeding srand()
  int _seedPrev;

 public:
  //! Constructor
  GameEngine();
  //! Destructor
  ~GameEngine();
  //! Init
  void Init();
  //! Operate on StateManager class object
  void HandleEvents(StateManager*);
  //! Update variables
  void Update();
  //! Draw on screen
  void Draw();
  //! Update seed variable for srand(). The seed value depend on pressed button and curFrame value at that time. Place it in main while().
  void update_seed();

};

#endif
