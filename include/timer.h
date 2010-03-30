#ifndef TIMER_H
#define TIMER_H

//!
class Timer {
 public:
  Timer();
  ~Timer();
  //! Timer ticks (return 1) after interval passed by arg.
  int correct_frame(int frameNum);
 private:
  //! Holds frames (or rather num. of how many times this method was executed).
  int curFrame;
};

#endif
