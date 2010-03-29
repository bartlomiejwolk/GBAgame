Timer::Timer(): curFrame(0) {
}

Timer::~Timer(){
}

//! Timer ticks in interval passed by arg.
int Timer::correct_frame(int frameNum) {
  curFrame++;

  // Return true after X passed frames. 
  if(curFrame == frameNum) {
    curFrame = 0;
    return true;
  }
  return false;
}
