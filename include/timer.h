#ifndef TIMER_H
#define TIMER_H

//!
class Timer {
 public:
  Timer();
  ~Timer();
  //! 
  int correct_frame(int frameNum);
 private:
  int curFrame;
};

#endif
