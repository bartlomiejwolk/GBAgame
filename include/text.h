#ifndef TEXT_H
#define TEXT_H

#include <tonc.h>
#include "timer.h"

//! Additional functionality for TTE.
/*!
  \par Dependencies for all text writing routines
  Set REG_DISPCNT to regular bg mode. Init regular tiles text engine with tte_init_se(). Add some color to pal_bg_bank[0][1]. In main while() use vid_vsync().
 */
class Text {
 public:
  //! Constructor
  /*!
    \param text string to be displayed
    \par Used by:
    xte_write_delayed()<br>
    xte_writeby_letter()
   */
  Text(const char* text);
  //! Constructor 2
  /*!
    \param[in] text text to display
    \param[in] timer pointer for Timer class obj. that ticks in some frame intervals.
   */
  Text(const char* text, Timer* timer);
  //! Destructor
  ~Text();
  //! Write characters one by one.
  /*!
    \par Description:
   Text to be written on screen must be given by class constructor Text::Text(const char*). This method must be executed at least as many times as many letter is to display.

    \param interval How many frames must pass before displaying another character. Frame in which the function is started is always frame 1. Character is displayed after so many frames as passed in argument. Minimum arg. is 1.
    \par Uses variables:
    Text::_ptimer
   */
  void xte_write_delayed(const int interval);
  //! Write text one character in each frame.
  /*!
    \par Todo:
    - Remove variable _textEnd and in the if statement use str var. instead.
    - Move str++ to the end to make it increment after a char is displayed.
   */
  void xte_writeby_letter();
  //! Write text like human
  void xte_writeby_human();
  //! Scroll text (like in the movies)
  /*!
    \par Todo:
    - add constraint to the line var. Max line can be 31*8
   */
  void xte_scroll_text();
  
  //! Helper function
  void draw_new_line();
  //! Helper function
  void  clear_line();

 private:
  char *str; 
  TTC *tc;
  uint ch, gid;
  TFont *font;
  //! Is set to 1 by instruction inside switch after last char is displayed.
  int _textEnd;
  int _curFrame;
  // screen position
  int y;

  //! Pointer for Timer obj. given by constructor
  /*!
    \par Used by:
    xte_write_delayed()<br>
    xte_writeby_human()
   */
  Timer* _ptimer;
};
#endif
