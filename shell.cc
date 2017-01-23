#include "labs/shell.h"
#include "labs/vgatext.h"

//
// initialize shellstate
//
void shell_init(shellstate_t& state){
    state.curr_pos = 0;
    state.execute = false;
    state.num_key = 0;
}

//
// handle keyboard event.
// key is in scancode format.
// For ex:
// scancode for following keys are:
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |back|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 01  | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0a | 0b | 0c | 0d | 0e |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | tab |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [ |  ] |entr|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 0f  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1a | 1b | 1c |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     |ctrl |  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ' |    |shft|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 1d  | 1e | 1f | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 2a |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
// so and so..
//
// - restrict yourself to: 0-9, a-z, esc, enter, arrows
// - ignore other keys like shift, control keys
// - only handle the keys which you're interested in
// - for example, you may want to handle up(0x48),down(0x50) arrow keys for menu.
//
void shell_update(uint8_t scankey, shellstate_t& s){
    hoh_debug("Got: "<<unsigned(scankey));
    ++s.num_key;
    switch(scankey){
        case 0x01 : // esc
            break;
        case 0x0e : // backspace
            --s.curr_pos;
            break;
        case 0x0f : // tab
            break;
        case 0x1c : // enter
            s.execute = true;
            break;
        case 0x1d : // ctrl
            break;
        case 0x2a : // shift
            break;

        case 0x02 : s.curr_cmd[s.curr_pos++] = '1';	break;
        case 0x03 : s.curr_cmd[s.curr_pos++] = '2';	break;
        case 0x04 : s.curr_cmd[s.curr_pos++] = '3';	break;
        case 0x05 : s.curr_cmd[s.curr_pos++] = '4';	break;
        case 0x06 : s.curr_cmd[s.curr_pos++] = '5';	break;
        case 0x07 : s.curr_cmd[s.curr_pos++] = '6';	break;
        case 0x08 : s.curr_cmd[s.curr_pos++] = '7';	break;
        case 0x09 : s.curr_cmd[s.curr_pos++] = '8';	break;
        case 0x0a : s.curr_cmd[s.curr_pos++] = '9';	break;
        case 0x0b : s.curr_cmd[s.curr_pos++] = '0';	break;
        case 0x0c : s.curr_cmd[s.curr_pos++] = '-';	break;
        case 0x0d : s.curr_cmd[s.curr_pos++] = '=';	break;
        // case 0x0e : s.curr_cmd[s.curr_pos++] = '1';	break;
        // case 0x0f : s.curr_cmd[s.curr_pos++] = '1';	break;
        case 0x10 : s.curr_cmd[s.curr_pos++] = 'q';	break;
        case 0x11 : s.curr_cmd[s.curr_pos++] = 'w';	break;
        case 0x12 : s.curr_cmd[s.curr_pos++] = 'e';	break;
        case 0x13 : s.curr_cmd[s.curr_pos++] = 'r';	break;
        case 0x14 : s.curr_cmd[s.curr_pos++] = 't';	break;
        case 0x15 : s.curr_cmd[s.curr_pos++] = 'y';	break;
        case 0x16 : s.curr_cmd[s.curr_pos++] = 'u';	break;
        case 0x17 : s.curr_cmd[s.curr_pos++] = 'i';	break;
        case 0x18 : s.curr_cmd[s.curr_pos++] = 'o';	break;
        case 0x19 : s.curr_cmd[s.curr_pos++] = 'p';	break;
        case 0x1a : s.curr_cmd[s.curr_pos++] = '[';	break;
        case 0x1b : s.curr_cmd[s.curr_pos++] = ']';	break;
        // case 0x1c : s.curr_cmd[s.curr_pos++] = '1';	break;
        // case 0x1d : s.curr_cmd[s.curr_pos++] = '1';	break;
        case 0x1e : s.curr_cmd[s.curr_pos++] = 'a';	break;
        case 0x1f : s.curr_cmd[s.curr_pos++] = 's';	break;
        case 0x20 : s.curr_cmd[s.curr_pos++] = 'd';	break;
        case 0x21 : s.curr_cmd[s.curr_pos++] = 'f';	break;
        case 0x22 : s.curr_cmd[s.curr_pos++] = 'g';	break;
        case 0x23 : s.curr_cmd[s.curr_pos++] = 'h';	break;
        case 0x24 : s.curr_cmd[s.curr_pos++] = 'j';	break;
        case 0x25 : s.curr_cmd[s.curr_pos++] = 'k';	break;
        case 0x26 : s.curr_cmd[s.curr_pos++] = 'l';	break;
        case 0x27 : s.curr_cmd[s.curr_pos++] = ';';	break;
        case 0x28 : s.curr_cmd[s.curr_pos++] = '\'';	break;
        case 0x29 : s.curr_cmd[s.curr_pos++] = ' ';	break;
        // case 0x2a : s.curr_cmd[s.curr_pos++] = '[';	break;
        // case 0x2b : s.curr_cmd[s.curr_pos++] = ']';	break;
        case 0x2c : s.curr_cmd[s.curr_pos++] = 'z';	break;
        case 0x2d : s.curr_cmd[s.curr_pos++] = 'x';	break;
        case 0x2e : s.curr_cmd[s.curr_pos++] = 'c';	break;
        case 0x2f : s.curr_cmd[s.curr_pos++] = 'v';	break;
        case 0x30 : s.curr_cmd[s.curr_pos++] = 'b';	break;
        case 0x31 : s.curr_cmd[s.curr_pos++] = 'n';	break;
        case 0x32 : s.curr_cmd[s.curr_pos++] = 'm';	break;
        case 0x33 : s.curr_cmd[s.curr_pos++] = ',';	break;
        case 0x34 : s.curr_cmd[s.curr_pos++] = '.';	break;
        case 0x35 : s.curr_cmd[s.curr_pos++] = '/';	break;
        // case 0x36 : s.curr_cmd[s.curr_pos++] = 'l';	break;
        // case 0x37 : s.curr_cmd[s.curr_pos++] = ';';	break;
        // case 0x38 : s.curr_cmd[s.curr_pos++] = '\'';	break;
        // case 0x39 : s.curr_cmd[s.curr_pos++] = ' ';	break;
        // case 0x3a : s.curr_cmd[s.curr_pos++] = '[';	break;
        // case 0x3b : s.curr_cmd[s.curr_pos++] = ']';	break;
        // case 0x3c : s.curr_cmd[s.curr_pos++] = 'z';	break;
        // case 0x3d : s.curr_cmd[s.curr_pos++] = 'x';	break;
        // case 0x3e : s.curr_cmd[s.curr_pos++] = 'c';	break;
        // case 0x3f : s.curr_cmd[s.curr_pos++] = 'v';	break;
        
        // default : // other keys
        //     s.curr_cmd[s.curr_pos++] = scankey;
        //     break;
    }
}


//
// do computation
//
void shell_step(shellstate_t& s){
    if(!s.execute) return;
  //
  //one way:
  // if a function is enabled in stateinout
  //   call that function( with arguments stored in stateinout) ;
//stateinout.args[0] = 5;
//stateinout.args[1] = 5;
  //
}


//
// shellstate --> renderstate
//
void shell_render(const shellstate_t& shell, renderstate_t& render){

  //
  // renderstate. number of keys pressed = shellstate. number of keys pressed
  //
  // renderstate. menu highlighted = shellstate. menu highlighted
  //
  // renderstate. function result = shellstate. output argument
  //
  // etc.
  //
}


//
// compare a and b
//
bool render_eq(const renderstate_t& a, const renderstate_t& b){
}


static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawtext(int x,int y, const char* str, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawnumberinhex(int x,int y, uint32_t number, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);

//
// Given a render state, we need to write it into vgatext buffer
//
void render(const renderstate_t& state, int w, int h, addr_t vgatext_base){


  // this is just an example:
  //
  // Please create your own user interface
  //
  // You may also have simple command line user interface
  // or menu based interface or a combination of both.
  //

}


//
//
// helper functions
//
//

static void writecharxy(int x, int y, uint8_t c, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  vgatext::writechar(y*w+x,c,bg,fg,vgatext_base);
}

static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  for(int y=y0;y<y1;y++){
    for(int x=x0;x<x1;x++){
      writecharxy(x,y,0,bg,fg,w,h,vgatext_base);
    }
  }
}

static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){

  writecharxy(x0,  y0,  0xc9, bg,fg, w,h,vgatext_base);
  writecharxy(x1-1,y0,  0xbb, bg,fg, w,h,vgatext_base);
  writecharxy(x0,  y1-1,0xc8, bg,fg, w,h,vgatext_base);
  writecharxy(x1-1,y1-1,0xbc, bg,fg, w,h,vgatext_base);

  for(int x=x0+1; x+1 < x1; x++){
    writecharxy(x,y0, 0xcd, bg,fg, w,h,vgatext_base);
  }

  for(int x=x0+1; x+1 < x1; x++){
    writecharxy(x,y1-1, 0xcd, bg,fg, w,h,vgatext_base);
  }

  for(int y=y0+1; y+1 < y1; y++){
    writecharxy(x0,y, 0xba, bg,fg, w,h,vgatext_base);
  }

  for(int y=y0+1; y+1 < y1; y++){
    writecharxy(x1-1,y, 0xba, bg,fg, w,h,vgatext_base);
  }
}

static void drawtext(int x,int y, const char* str, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  for(int i=0;i<maxw;i++){
    writecharxy(x+i,y,str[i],bg,fg,w,h,vgatext_base);
    if(!str[i]){
      break;
    }
  }
}

static void drawnumberinhex(int x,int y, uint32_t number, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  enum {max=sizeof(uint32_t)*2+1};
  char a[max];
  for(int i=0;i<max-1;i++){
    a[max-1-i-1]=hex2char(number%16);
    number=number/16;
  }
  a[max-1]='\0';

  drawtext(x,y,a,maxw,bg,fg,w,h,vgatext_base);
}

