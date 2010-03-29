#include <vector>
#include "gameengine.h"
#include "gamestate.h"
#include "statemanager.h" // or forward class

using namespace std;

GameEngine::GameEngine() {

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
