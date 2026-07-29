#include "../assets.h"
#include <cctype>
#include <SDL2/SDL_timer.h>
#include<iostream>
#include<string>
#include<fstream>

void save(){
  std::ofstream file("CGE_save.txt"); 

  if(file.is_open()){
    //colors
    for(int i = 0; i < colors.size() - 1; i++){
      file << colors[i] << ',' << '\n';
    }
    file << colors[colors.size() - 1] << '\n';
    //canvas
    for(int i = 0; i < canvas_size_y; i++){
      for(int j = 0; j < canvas_size_x; j++){
        if(i != canvas_size_y - 1 || j != canvas_size_x - 1)file << canvas[i*canvas_size_x+j] << ',';
      }
      if(i != canvas_size_y - 1)file << '\n';
    }
    
    file << canvas[canvas.size() - 1] << '\n';
  }

  file.close();
}

void text(std::string s, short x, short y, uint8_t col, uint8_t size){
  int l = 6;
  for(char &p: s){
    if(p != ' '){
      if(std::isalpha(p))
        for(int i = 0; i < 13; i++){
          for(int j = 0; j < 5; j++){
            if(font[p-'a'][i*5+j]){
              for(int i2 = 0; i2 < size; i2++){
                for(int j2 = 0; j2 < size; j2++){
                  screen[(y+i*size+i2)*window_width + x + j*size + j2].first = 1;
                  screen[(y+i*size+i2)*window_width + x + j*size + j2].second = col;
                }
              }
            }
          }
        }
      else 
        for(int i = 0; i < 13; i++){
          for(int j = 0; j < 5; j++){
            if(font_num[p-'0'][i*5+j]){
              for(int i2 = 0; i2 < size; i2++){
                for(int j2 = 0; j2 < size; j2++){
                  screen[(y+i*size+i2)*window_width + x + j*size + j2].first = 1;
                  screen[(y+i*size+i2)*window_width + x + j*size + j2].second = col;
                }
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
      case 1:
        l = 4; 
      break;
      default:
        l = 6;
      break;
    }
    x += l * size;
  }
}
