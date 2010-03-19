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
  /// Handle user input.
  virtual void HandleEvents() = 0;
  virtual void Update() = 0;
  virtual void Display() = 0; // (?)

};

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
