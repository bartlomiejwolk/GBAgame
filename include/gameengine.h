#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "gamestate.h"
#include "statemanager.h"

/*! GameEngine */
class GameEngine {

 private:

 public:
  //! Constructor
  GameEngine();
  //! Destructor
  ~GameEngine();
  //! Init
  void Init();
  //! Operate on StateManager object
  void HandleEvents(StateManager*);
  //! Update variables
  void Update();
  //! Draw on screen
  void Draw();

};

#endif
