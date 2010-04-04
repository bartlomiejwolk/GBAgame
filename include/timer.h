#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>

//!
class Timer {
 public:
  Timer();
  //! Initialize variables for random_frame().
  /*!
    \param g1_min Minimum frame for generator 1 that can be drawn.
    \param g1_max Maximum frame for generator 1 that can be drawn.
    \param g2_min 
    \param g2_max
    \param g1_prob Probability that g1 will be used rather than g2.
   */
  Timer(int, int, int, int, int);
  ~Timer();
  //! method
  /*!
    \c _curFrame[0]
    \return  true after interval passed by arg.
  */
  int frame(int frameNum);

  //! short
  /*!
    Arguments are given to the constructor.

    \b Uses: \n
    \c int _curFrame[1] \n
    \c GENERATOR _gen
    
    \return true at random frame.
    \sa Timer(int, int, int, int, int)
   */
  int random_frame();
  //! Return _curFrame
  /*!
    \param num _curFrame has two instances. See _curFrame[].
  */
  int get_curframe(int num){
    return _curFrame[num];
  }
  //! Set _curFrame[]
  void set_curframe(int frame){
    _curFrame[0] = frame;
  }

 private:
  //! Variable
  /*!
    Holds number of how many times a method was executed.
\sa frame() [0]
\sa random_frame() [1]
  */
  int _curFrame[2];

  //! Variables for method random_frame()
  struct GENERATOR {
    //! active == 1 means that there shoulnd't be drawn another frame_value because the method is waiting to return 1 at previous frame_value.
    int active;
    int g1min;
    int g1max;
    int g2min;
    int g2max;
    int g1prob;
    int g1range;
    int g2range;
    int genNum;
  }_gen;

  int _frameValue;

};

#endif
