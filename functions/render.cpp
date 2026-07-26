#include "../assets.h"
#include<iostream>
#include<string>

void screen_paint(){
  for(uint16_t i = 0; i < window_height; i++){
    for(uint16_t j = 0; j < window_width; j++){
      screen[i*window_width+j] = 0;
    }
  }
  
}

void screen_conversion(){
  for(int i = 0; i < window_height * window_width; i++){
    final_screen[i] = pallete[screen[i]];
  }
}
