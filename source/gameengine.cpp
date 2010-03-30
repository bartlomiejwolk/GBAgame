#include <stdlib.h>
#include <vector>
#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h" // or forward class

using namespace std;

GameEngine::GameEngine(): seed_curr(736254) {

}

GameEngine::~GameEngine() {

}

void GameEngine::Init() {
  
}

void GameEngine::HandleEvents(StateManager* stateManager) {
  vector<IGameState*>* states;
  states = stateManager->ReturnStates(); // states is holding pointer to states vector
  states->back()->HandleEvents(); // let current state handle events

}

void GameEngine::Update() {

};

void GameEngine::Draw() {


}

// --- update_seed() ---
void GameEngine::update_seed(){
  frame_curr++;
 
  if (frame_curr == 65535) // It's the safe value. I'm not sure if 2^32 (4294967296) wouldn't make overflow.
     frame_curr = 0;

  // Update seed only when any key is pressed.
  if (key_hit(KEY_ANY)) {
    seed_prev = seed_curr;
    seed_curr = frame_curr;
  }
  // When no button is pressed, the previous frame will be always as current.
  else
    seed_prev = seed_curr;

  // Update seed using srand()
  if (seed_curr != seed_prev)
    srand(seed_curr);
}
// ^^^ update_seed() ^^^
