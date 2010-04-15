#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>

//! Returns true after any given period of time
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
    \param[in] frameNum Number of frames where when method will be inactive.
    \par Uses:
    \c Timer::_curFrame[0]
    \return  true after interval passed by arg.
  */
  int frame(int frameNum);

  //! Timer that ticks irregularly
  /*!
    \par Description
    Define two frame ranges and a probability to use one of them. Arguments are given to the Timer(int, int, int, int, int) and are described there.

    \par Uses:
    \c int Timer::_curFrame[1] \n
    \c GENERATOR Timer::_gen
    
    \return true at random frame.
  */
  int random_frame();
  //! Return _curFrame
  /*!
    \param num _curFrame has two instances. See _curFrame[].
  */
  int get_curframe(int num){
    return _curFrame[num];
  }
  //! Set variable int Timer::_curFrame[]
  /*!

   */
  void set_curframe(int frame){
    _curFrame[0] = frame;
  }

 private:
  //! Holds number of how many times a method was executed.
  /*!
    \par Is used by: 
     frame() \n
     random_frame()
  */
  int _curFrame[2];

  //! Variables for method random_frame()
  /*!

   */
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
  
  //! This value is randomly generated. Used to know after how many frames return true.
  /*!
    \par Is used by
    random_frame()
   */
  int _frameValue;

};

#endif

