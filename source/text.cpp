#include "text.h"

// forward declaration
extern "C" uint utf8_decode_char(const char *ptr, char **endptr);

Text::Text(const char* text): str((char*)text), tc(tte_get_context()), textEnd(0), curFrame(0){ 
    
}

Text::~Text(){

}

int Text::xte_write_delayed(const int interval){
  
  // Display text only after so many frames as given in the arg.
  if(timer.correct_frame(interval)){
  
  str++;
  ch = *str; 
  // Everything within switch is to interpret and display text on screen. When all text given by arg. is displayed, there is no need to go inside this switch again.
  if (textEnd == 0){
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
	textEnd = 1;
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
  
  return 1; // value has no meaning
    }
    return 0;
}
