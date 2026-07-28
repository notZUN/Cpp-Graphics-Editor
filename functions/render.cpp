#include "../assets.h"
#include<iostream>
#include<string>

void paint_set_color_color(int part, int color, float part_start_x, float part_x, float part_start_y, float part_y){
  for(uint16_t i = part_start_y; i < part_start_y + part_y; i++){
    for(uint16_t j = part_start_x + part_x * part; j < part_start_x + part_x * (part+1); j++){
      screen[i*window_width+j] = color;
    }
  }
}

void paint_set_color(float size_x, float size_y){
  float part_start_x = window_width / size_x;
  float part_end_x = window_width - part_start_x;
  float part_x = (part_end_x - part_start_x)/7;
  float part_start_y = window_height / size_y;
  float part_end_y = window_height - part_start_y;
  float part_y = (part_end_y - part_start_y)/3;
  
  for(uint16_t i = part_start_y; i < part_start_y + part_y * 3; i++){
    for(uint16_t j = part_start_x; j < part_start_x + part_x * 7; j++){
      screen[i*window_width+j] = 5;
    }
  }

  paint_set_color_color(0, 6, part_start_x, part_x, part_start_y, part_y);
  
};

void paint_canvas(){
  int start_y = 0;
  int end_y = window_height;
  float part_y = (end_y - start_y) / canvas_size_y; 
  int start_x = 0;
  int end_x = window_width;
  float part_x = (end_x - start_x) / canvas_size_x;

  for(int i = 0; i < canvas_size_y; i++){
    for(int j = 0; j < canvas_size_x; j++){
      for(int i2 = start_y + i * part_y; i2 < start_y + (i + 1) * part_y; i2++){
        for(int j2 = start_x + j * part_x; j2 < start_x + (j + 1) * part_x; j2++){
          if(((i + j)&1)==0)screen[i2*window_width+j2] = 0;
            else screen[i2*window_width+j2] = 5;
        }
      }
    }
  }
};

void screen_paint(){
  for(uint16_t i = 0; i < window_height; i++){
    for(uint16_t j = 0; j < window_width; j++){
      screen[i*window_width+j] = 1;
    }
  }
  if(set_color)paint_set_color(6, 3);

  paint_canvas();
}

void screen_conversion(){
  for(int i = 0; i < window_height * window_width; i++){
    final_screen[i] = pallete[screen[i]];
  }
}
