#include "timer.h"

Timer::Timer(int g1_min, int g1_max, int g2_min, int g2_max, int g1_prob) {
  // !!! There should be better way to initialize these.
  _curFrame[0] = 0;
  _curFrame[1] = 0;

  _gen.active = 0;
  _gen.g1min = g1_min;
  _gen.g1max = g1_max;
  _gen.g2min = g2_min;
  _gen.g2max = g2_max;
  _gen.g1prob = g1_prob;
  _gen.g1range = g1_max - g1_min;
  _gen.g2range = g2_max - g2_min;
}

Timer::Timer(){

};

Timer::~Timer(){
}

int Timer::frame(int frameNum) {
  _curFrame[0]++;

  // Return true after X passed frames. 
  if(_curFrame[0] == frameNum) {
    _curFrame[0] = 0;
    return true;
  }
  return false;
}

int Timer::random_frame(){

  _curFrame[1]++; 
 
  // draw another frame?
  if (!_gen.active){
    
    // Draw g1 or g2
    _gen.genNum = rand() % 100 + 1;
    
    // if g1
    if (_gen.genNum <= _gen.g1prob)
      // Draw frame from g1
      _frameValue = rand() % (_gen.g1range + 1) + _gen.g1min;
    else
      // Draw frame from g2
      _frameValue = rand() % (_gen.g2range + 1) + _gen.g2min;
    
    _gen.active = 1;
  }
  
  // Return true when it's time
  if (_frameValue == _curFrame[1]){
    _gen.active = 0;
    _curFrame[1] = 0;
    return true;
  }
  
  return false;
}
