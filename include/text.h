#ifndef TEXT_H
#define TEXT_H

#include <tonc.h>
#include "timer.h"

//! Additional functionality for TTE.
class Text {
 public:
  //! Constructor for xte_write_delayed() and xte_writeby_letter()
  /*!
    \param text string to be displayed
   */
  Text(const char* text);
  //! Constructor for xte_writeby_human()
  Text(const char* text, int, int, int, int, int);
  ~Text();
  //! Write characters one by one. Text to be written on screen must be given by class constructor. This method must be executed at least as many times as many letter is to display.
  /*
    \ param intervall How many frames must pass before displaying another character. Frame in which the function is started is always frame 1. Character is displayed after so many frames as passed in argument. Minimum arg. is 1.
    Dependencies: Set REG_DISPCNT to regular bg mode. Init regular tiles text engine with tte_init_se(). Add some color to pal_bg_bank[0][1]. In main while() use vid_vsync().
   */
  void xte_write_delayed(const int intervall);
  //! Write text one character in each frame.
  void xte_writeby_letter();
  void xte_writeby_human();

 private:
  char *str; 
  TTC *tc;
  uint ch, gid;
  TFont *font;
  //! Is set to 1 by instruction inside switch after last char is displayed.
  int textEnd;
  int curFrame;
  Timer timer;
};
#endif
