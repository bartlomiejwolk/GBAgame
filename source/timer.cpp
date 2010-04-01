#include "timer.h"

Timer::Timer(int g1_min, int g1_max, int g2_min, int g2_max, int g1_prob): _curFrame(0), _frame_curr(0), _active(0), _g1_min(g1_min), _g1_max(g1_max), _g2_min(g2_min), _g2_max(g2_max), _g1_prob(g1_prob), _g1_range(g1_max - g1_min), _g2_range(g2_max - g2_min) {
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

  _frame_curr++;
 
  // draw another frame?
  if (!_active){
    
    // Draw g1 or g2
    _generator = rand() % 100 + 1;
    
    // if g1
    if (_generator <= _g1_prob)
      // Draw frame from g1
      _frame_value = rand() % (_g1_range + 1) + _g1_min;
    else
      // Draw frame from g2
      _frame_value = rand() % (_g2_range + 1) + _g2_min;
    
    _active = 1;
  }
  
  // Return true when it's time
  if (_frame_value == _frame_curr){
    _active = 0;
    _frame_curr = 0;
    return true;
  }
  
  return false;
}
