#include "../assets.h"
#include<iostream>
#include<string>

void paint_new_color_color(int part, int color, float part_start_x, float part_x, float part_start_y, float part_y){
  for(uint16_t i = part_start_y; i < part_start_y + part_y; i++){
    for(uint16_t j = part_start_x + part_x * part; j < part_start_x + part_x * (part+1); j++){
      screen[i*window_width+j].first = 1;
      screen[i*window_width+j].second = color;
    }
  }
}

void paint_new_color_color_new(int part, float part_start_x, float part_x, float part_start_y, float part_y){
  for(uint16_t i = part_start_y + part_y; i < part_start_y + part_y * 2; i++){
    for(uint16_t j = part_start_x + part_x * part; j < part_start_x + part_x * (part+1); j++){
      screen[i*window_width+j].first = 0;
      screen[i*window_width+j].second = colors.size() - 1;
    }
  }
}

void new_color_conv(){
  colors[colors.size()-1] = ((new_color_rgb[0] << 11) | (new_color_rgb[1] << 5) | new_color_rgb[2]);
};

void paint_new_color_text(int part, float part_start_x, float part_x, float part_start_y, float part_y){
  if(part == set) text(std::to_string(new_color_rgb[part]), int(part_start_x + part * part_x + part_x * 0.2), int(part_start_y + part_y * 1.2), 4, 4);
  else text(std::to_string(new_color_rgb[part]), int(part_start_x + part * part_x + part_x * 0.2), int(part_start_y + part_y * 1.2), 0, 4);
};

void paint_new_color(float size_x, float size_y){
  float part_start_x = window_width / size_x;
  float part_end_x = window_width - part_start_x;
  float part_x = (part_end_x - part_start_x)/4;
  float part_start_y = window_height / size_y;
  float part_end_y = window_height - part_start_y;
  float part_y = (part_end_y - part_start_y)/2;
  
  for(uint16_t i = part_start_y; i < part_start_y + part_y * 2; i++){
    for(uint16_t j = part_start_x; j < part_start_x + part_x * 4; j++){
      screen[i*window_width+j].first = 1;
      screen[i*window_width+j].second = 8;
    }
  }

  paint_new_color_color(0, 6, part_start_x, part_x, part_start_y, part_y);
  paint_new_color_color(1, 7, part_start_x, part_x, part_start_y, part_y);
  paint_new_color_color(2, 2, part_start_x, part_x, part_start_y, part_y);
  
  new_color_conv();

  paint_new_color_color_new(3, part_start_x, part_x, part_start_y, part_y); 
  paint_new_color_text(0, part_start_x, part_x, part_start_y, part_y);
  paint_new_color_text(1, part_start_x, part_x, part_start_y, part_y);
  paint_new_color_text(2, part_start_x, part_x, part_start_y, part_y);
};

void paint_size_text_top(float part_start_x, float part_x, float part_start_y, float part_y){
  if(set == 0)text("x", int(part_start_x + part_x * 0.2), int(part_start_y), 4, 5);
  else text("x", int(part_start_x + part_x * 0.2), int(part_start_y), 0, 5);
  if(set == 1)text("y", int(part_start_x + part_x * 1.2), int(part_start_y), 4, 5);
  else text("y", int(part_start_x + part_x * 1.2), int(part_start_y), 0, 5);
};

void paint_size_text_bottom(float part_start_x, float part_x, float part_start_y, float part_y){
  if(set == 0)text(std::to_string(canvas_size_x), int(part_start_x + part_x * 0.2), int(part_start_y), 4, 5);
  else text(std::to_string(canvas_size_x), int(part_start_x + part_x * 0.2), int(part_start_y), 0, 5);
  if(set == 1)text(std::to_string(canvas_size_y), int(part_start_x + part_x * 1.2), int(part_start_y), 4, 5);
  else text(std::to_string(canvas_size_y), int(part_start_x + part_x * 1.2), int(part_start_y), 0, 5);
};

void paint_size(float size_x, float size_y){
  float part_start_x = window_width / size_x;
  float part_end_x = window_width - part_start_x;
  float part_x = (part_end_x - part_start_x)/2;
  float part_start_y = window_height / size_y;
  float part_end_y = window_height - part_start_y;
  float part_y = (part_end_y - part_start_y)/2;
  
  for(uint16_t i = part_start_y; i < part_start_y + part_y * 2; i++){
    for(uint16_t j = part_start_x; j < part_start_x + part_x * 2; j++){
      screen[i*window_width+j].first = 1;
      screen[i*window_width+j].second = 8;
    }
  }

  paint_size_text_top(part_start_x, part_x, part_start_y, part_y);
  paint_size_text_bottom(part_start_x, part_x, part_start_y + part_y, part_y); 
};

void paint_canvas(){
  int start_y = 50;
  int end_y = window_height;
  float part_y = (end_y - start_y) / canvas_size_y; 
  int start_x = 0;
  int end_x = window_width;
  float part_x = (end_x - start_x) / canvas_size_x;

  for(int i = 0; i < canvas_size_y; i++){
    for(int j = 0; j < canvas_size_x; j++){
      for(int i2 = start_y + i * part_y; i2 < start_y + (i + 1) * part_y; i2++){
        for(int j2 = start_x + j * part_x; j2 < start_x + (j + 1) * part_x; j2++){
          if(canvas[i * canvas_size_x + j] == 255){
            if(((i + j)&1)==0){
              screen[i2*window_width+j2].first = 1;
              screen[i2*window_width+j2].second = 0;
            }
            else{
                screen[i2*window_width+j2].first = 1;
                screen[i2*window_width+j2].second = 5;
              }
          }
          else{
            screen[i2*window_width+j2].first = 0;
            screen[i2*window_width+j2].second = canvas[i * canvas_size_x + j];
          }
        }
      }
      if(i == canvas_set_y && j == canvas_set_x){
        for(int l = 0; l < part_x; l++){
          screen[int((start_y + (i+1) * part_y - 1)*window_width + start_x + j * part_x + l)].first = 0; 
          screen[int((start_y + (i+1) * part_y - 1)*window_width + start_x + j * part_x + l)].second = select_color; 
        }
      }
    }
  }
};

void paint_colors(){
  int start_y = 0;
  int end_y = 50;
  int start_x = 0;
  int end_x = window_width;
  float part_x = (end_x - start_x) / colors.size();

  for(int k = 0; k < colors.size(); k++){
    for(int i = start_y; i < end_y; i++){
      for(int j = start_x + k * part_x; j < start_x + (k+1) * part_x; j++){
        screen[i*window_width+j].first = 0;
        screen[i*window_width+j].second = k;
      }
    }
    if(k == select_color){
      for(int i = start_x + k * part_x; i < start_x + (k + 1) * part_x; i++){
        screen[(end_y-1)*window_width+i].first = 1;
        screen[(end_y-1)*window_width+i].second = 7;
      } 
    }
  }
};

void screen_paint(){
  paint_colors();
  paint_canvas();
  if(state == State::new_color){
    paint_new_color(4, 4);
  }
  if(state == State::size){
    paint_size(3, 4);
  }
}

void screen_conversion(){ 
  for(int i = 0; i < window_height * window_width; i++){
    if(screen[i].first)final_screen[i] = pallete[screen[i].second];
    else final_screen[i] = colors[screen[i].second];
  }
}
