#include "text.h"

// forward declaration
extern "C" uint utf8_decode_char(const char *ptr, char **endptr);

Text::Text(const char* text): str((char*)text), tc(tte_get_context()), _textEnd(0), _curFrame(0){ 
  
}

// Second constructor (overloaded)
Text::Text(const char* text, Timer* timer): str((char*)text), tc(tte_get_context()), _textEnd(0), _curFrame(0), y(0){
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

void Text::xte_writeby_letter(){
  str++;
  ch = *str; 

  // Everything within switch is to interpret and display text on screen. When all text given by str is displayed, there is no need to go inside this switch again.
  if (_textEnd == 0){

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
	_textEnd = 1;
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
}

void Text::xte_writeby_human(){
  if (_ptimer->random_frame())
    xte_writeby_letter();
}

void Text::xte_scroll_text(){
  // scroll bg
  if (_ptimer->frame(3)) {
    y++;
    REG_BG0VOFS = y;
  }
  
  // reset y
  if (y == 32*8) {
    y = 0;
  }

  // 8px
  if (y % 8 == 0)
    draw_new_line();
}

void Text::draw_new_line() {
  //while( (ch=*str) != '\0' )
  while ((ch=*str) != '\n')
    {
      str++;
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
}
