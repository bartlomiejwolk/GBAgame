#ifndef TIMER_H
#define TIMER_H

//!
class Timer {
 public:
  Timer();
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
  int random_frame(int g1_beg, int g1_end, int g2_beg, int g2_end, int g1_prob);

 private:
  //! Holds frames (or rather num. of how many times this method correct_frame() was executed).
  int curFrame;
  //! Holds frames (or rather num. of how many times this method random_frame() was executed).
  int curFrame2;
};

#endif
