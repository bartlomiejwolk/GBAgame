#include "text.h"

// forward declaration
extern "C" uint utf8_decode_char(const char *ptr, char **endptr);

Text::Text(const char* text): str((char*)text), tc(tte_get_context()), _textEnd(0), _curFrame(0){ 
  // by default ch contains "\0" character. If it's not changed then xte_writeby_letter() will think that there is no text to display
  ch = 1;
}

// Second constructor (overloaded)
Text::Text(const char* text, Timer* timer): str((char*)text), tc(tte_get_context()), _textEnd(0), _curFrame(0), y(11*8) {
  _ptimer = timer;
}

Text::~Text(){

}

void Text::xte_write_delayed(const int interval){
    // Display text only after so many frames as given in the arg.
  if(_ptimer->frame(interval))
    // Write another letter
    xte_writeby_letter();
}

int Text::xte_writeby_letter(){
  
  // stop writing text
  if (ch == '\0')
    return 0;

  str++;
  ch = *str; 
  
  // when bg ends, start writing from the beginning of the bg
  if (tc->cursorY == (32*8))
    tc->cursorY = 0;

    switch(ch)
      {
	// --- Newline/carriage return ---
      case '\r':
	if(str[0] == '\n')	// deal with CRLF pair
	  str++;
	// FALLTHRU
      case '\n':
	tc->cursorY += tc->font->charH;
	tc->cursorX  = tc->marginLeft;
	break;
	// --- Tab ---
      case '\t':
	tc->cursorX= (tc->cursorX/TTE_TAB_WIDTH+1)*TTE_TAB_WIDTH;
	break;
      case '\0':
	break;
	// --- Normal char ---
      default:
	// Command sequence
	if(ch=='#' && str[0]=='{')
	  {
	    str= tte_cmd_default(str+1);
	    break;
	  }
	// Escaped command: skip '\\' and print '#'
	else if(ch=='\\' && str[0]=='#')
	  ch= *str++;
	// Check for UTF8 code
	else if(ch>=0x80)
	  ch= utf8_decode_char(str-1, &str);
	
	// Get glyph index and call renderer
	font= tc->font;
	gid= ch - font->charOffset;
	if(tc->charLut)
	  gid= tc->charLut[gid];
	
	// Character wrap
	int charW= font->widths ? font->widths[gid] : font->charW;
	if(tc->cursorX+charW > tc->marginRight)
	  {
	    tc->cursorY += font->charH;
	    tc->cursorX  = tc->marginLeft;
	  }
	
	// Draw and update position
	tc->drawgProc(gid);
	tc->cursorX += charW;
      }
}

void Text::xte_writeby_human(){
  if (_ptimer->random_frame())
    xte_writeby_letter();
}

void Text::xte_scroll_text(){
   // scroll bg
  if (_ptimer->frame(2)) {
    y++;
    REG_BG0VOFS = y;
    
    // 8px
    if ((y % 8) == 0) {
      clear_line();
      // if statement added
      if ((ch = *str) != '\0')
	draw_new_line();
    }
  }

  // reset y
  if (y == 32*8) {
    y = 0;
  }
}

void Text::draw_new_line() {
  while ((ch=*str) != '\n')
    xte_writeby_letter();
  str++;
}


void Text::clear_line() {
  // save tc->positionX and Y
  int cursorX_val = tc->cursorX;
  int cursorY_val = tc->cursorY;
  
  // wouldn't it be better to clear with zeros the memory area of that line?
  tte_write("                    ");

  // restore saved values
  tc->cursorX = cursorX_val;
  tc->cursorY = cursorY_val;
}
