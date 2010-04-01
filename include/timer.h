#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>

//!
class Timer {
 public:
  Timer();
  Timer(int, int, int, int, int);
  ~Timer();
  //! Timer ticks (return 1) after interval passed by arg.
  int correct_frame(int frameNum);

    //! Return 1 at random frame.
  /*
    \param g1_beg Minimum interval for generator 1 (in frames) that can be drawn.
    \param g1_end Maximum interval for generator 1 that can be drawn.
    \param g2_beg 
    \param g2_end
    \param g1_prob Probability that g1 will be used rather than g2.
   */
  int random_frame();

 private:
  //! Holds frames (or rather num. of how many times this method correct_frame() was executed).
  int _curFrame;
  //! Holds frames (or rather num. of how many times this method random_frame() was executed).
  int _frame_curr;
  //! active == 1 means that there shoulnd't be drawn another frame_value because the method is waiting to return 1 at previous frame_value.
  int _active;
  int _g1_min;
  int _g1_max;
  int _g2_min;
  int _g2_max;
  int _g1_prob;
  int _frame_value;
  int _g1_range;
  int _g2_range;
  int _generator;

};

#endif
