#include "timer.h"

Timer::Timer(): curFrame(0) {
}

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

int Timer::random_frame(int g1_ben, int g1_end, int g2_beg, int g2_end, int g1_prob) {
  curFrame2++;

  

  // when comes drawn frame num.
  return true;
}
