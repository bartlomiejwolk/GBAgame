#ifndef GAMESTATE_H
#define GAMESTATE_H

/** IGameState */
class IGameState {

private:

public:
  //! Constructor
  IGameState();
  //! Destructor
  virtual  ~IGameState();
  virtual void Init() = 0 ;
  virtual void CleanUp() = 0; // (?)
  //! Handle user input.
  virtual void HandleEvents() = 0;
  virtual void Update() = 0;
  virtual void Display() = 0; // (?)

};

#endif
