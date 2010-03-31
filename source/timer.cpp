#include "timer.h"

Timer::Timer(int g1_min, int g1_max, int g2_min, int g2_max, int g1_prob): curFrame(0), frame_curr(0), active(0), _g1_min(g1_min), _g1_max(g1_max), _g2_min(g2_min), _g2_max(g2_max), _g1_prob(g1_prob), g1_range(g1_max - g1_min), g2_range(g2_max - g2_min) {
}

Timer::Timer(){

};

Timer::~Timer(){
}

int Timer::correct_frame(int frameNum) {
  curFrame++;

  // Return true after X passed frames. 
  if(curFrame == frameNum) {
    curFrame = 0;
    return true;
  }
  return false;
}

int Timer::random_frame(){

  frame_curr++;
 
  // draw another frame?
  if (!active){

  // Draw g1 or g2
  generator = rand() % 100 + 1;
  
  // if g1
  if (generator <= _g1_prob)
  // Draw frame from g1
    frame_value = rand() % (_g1_min+1) + g1_range;
  else
    // Draw frame from g2
    frame_value = rand() % (_g2_min+1) + g2_range;

  active = 1;
  }
  
  // Return true when it's time
  if (frame_value == frame_curr){
    active = 0;
    frame_curr = 0;
    return true;
  }

  return false;
}
