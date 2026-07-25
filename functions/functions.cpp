#include "../assets.h"
#include <SDL2/SDL_timer.h>
#include<iostream>
#include<string>

void text(std::string s, short x, short y, uint8_t col, uint8_t size){
  int l = 6;
  for(char &p: s){
    if(p != ' ')for(int i = 0; i < 13; i++){
      for(int j = 0; j < 5; j++){
        if(font[p-'a'][i*5+j]){
          for(int i2 = 0; i2 < size; i2++){
            for(int j2 = 0; j2 < size; j2++){
              screen[(y+i*size+i2)*window_width + x + j*size + j2] = col;
            }
          }
        }
      }
    }
    switch(p){
      case 'i':
      case 'l':
        l = 2;
      break;
      case 'f':
      case 't':
      case 'k':
        l = 5;
      break;
      case 'j':
        l = 3;
      break;
      default:
        l = 6;
      break;
    }
    x += l * size;
  }
}
