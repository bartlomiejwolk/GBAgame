#include "timer.h"

Timer::Timer(int g1_min, int g1_max, int g2_min, int g2_max, int g1_prob): _curFrame(0), _frameCurr(0), _active(0), _g1Min(g1_min), _g1Max(g1_max), _g2Min(g2_min), _g2Max(g2_max), _g1Prob(g1_prob), _g1Range(g1_max - g1_min), _g2Range(g2_max - g2_min) {
}

Timer::Timer(){

};

Timer::~Timer(){
}

int Timer::frame(int frameNum) {
  _curFrame++;

  // Return true after X passed frames. 
  if(_curFrame == frameNum) {
    _curFrame = 0;
    return true;
  }
  return false;
}

int Timer::random_frame(){

  _frameCurr++;
 
  // draw another frame?
  if (!_active){
    
    // Draw g1 or g2
    _generator = rand() % 100 + 1;
    
    // if g1
    if (_generator <= _g1Prob)
      // Draw frame from g1
      _frameValue = rand() % (_g1Range + 1) + _g1Min;
    else
      // Draw frame from g2
      _frameValue = rand() % (_g2Range + 1) + _g2Min;
    
    _active = 1;
  }
  
  // Return true when it's time
  if (_frameValue == _frameCurr){
    _active = 0;
    _frameCurr = 0;
    return true;
  }
  
  return false;
}
