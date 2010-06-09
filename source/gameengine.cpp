#include <stdlib.h>
#include <vector>
#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h" // or forward class

using namespace std;

GameEngine::GameEngine(): _seedCurr(736254) {

}

GameEngine::~GameEngine() {

}

void GameEngine::init() {
  
}

void GameEngine::handle_events(StateManager* stateManager) {
  vector<IGameState*>* _states;
  _states = stateManager->ReturnStates(); // states is holding pointer to states vector
  _states->back()->HandleEvents(); // let current state handle events

}

void GameEngine::update(StateManager* stateManager) {
  
};

void GameEngine::draw() {


}

void GameEngine::update_seed(){
 
  // 
  if (_timer.frame(65535)) // It's the safe value. I'm not sure if 2^32 (4294967296) wouldn't make overflow.
    _timer.set_curframe(0);

  // Update seed only when any key is pressed.
  if (key_hit(KEY_ANY)) {
    _seedPrev = _seedCurr;
    _seedCurr = _timer.get_curframe(0);
  }
  // When no button is pressed, the previous frame will be always as current.
  else
    _seedPrev = _seedCurr;

  // Update seed using srand() but only in the frame when any button was pressed.
  if (_seedCurr != _seedPrev)
    srand(_seedCurr);
}

