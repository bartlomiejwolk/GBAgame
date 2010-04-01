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

void GameEngine::Init() {
  
}

void GameEngine::HandleEvents(StateManager* stateManager) {
  vector<IGameState*>* _states;
  _states = stateManager->ReturnStates(); // states is holding pointer to states vector
  _states->back()->HandleEvents(); // let current state handle events

}

void GameEngine::Update() {

};

void GameEngine::Draw() {


}

void GameEngine::update_seed(){
  _frameCurr++;
 
  if (_frameCurr == 65535) // It's the safe value. I'm not sure if 2^32 (4294967296) wouldn't make overflow.
     _frameCurr = 0;

  // Update seed only when any key is pressed.
  if (key_hit(KEY_ANY)) {
    _seedPrev = _seedCurr;
    _seedCurr = _frameCurr;
  }
  // When no button is pressed, the previous frame will be always as current.
  else
    _seedPrev = _seedCurr;

  // Update seed using srand()
  if (_seedCurr != _seedPrev)
    srand(_seedCurr);
}

