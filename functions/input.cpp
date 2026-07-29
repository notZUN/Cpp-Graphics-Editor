#include "../assets.h"
#include <SDL2/SDL.h>
#include<iostream>
#include<string>

void input(){
  const uint8_t* keystate = SDL_GetKeyboardState(NULL);
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT) running = false;
    if(event.type == SDL_KEYDOWN){ 
      if(state == State::canvas)switch(event.key.keysym.sym){
          case SDLK_l:
            if(canvas_set_y > 0)canvas_set_y--;
            else canvas_set_y = canvas_size_y - 1; 
          break;
          case SDLK_k:
            if(canvas_set_y < canvas_size_y - 1)canvas_set_y++;
            else canvas_set_y = 0; 
          break;

          case SDLK_j:
            if(canvas_set_x > 0)canvas_set_x--;
            else canvas_set_x = canvas_size_x - 1; 
          break;
          case SDLK_SEMICOLON:
            if(canvas_set_x < canvas_size_x - 1)canvas_set_x++;
            else canvas_set_x = 0; 
          break;

          case SDLK_w:
            if(select_color > 0){
              select_color--;
            }
            else select_color = colors.size() - 1;
          break;
          case SDLK_e:
            if(select_color < colors.size() - 1){
              select_color++;
            }
            else select_color = 0;
          break;
          
        case SDLK_a:
          state = State::new_color;
          new_color_rgb[0] = 0;
          new_color_rgb[1] = 0;
          new_color_rgb[2] = 0;
          colors.push_back(31);
        break;
        case SDLK_q:
          colors.erase(colors.begin() + colors.size() - 1);
        break;
      }
      else if(state == State::new_color)switch(event.key.keysym.sym){
          case SDLK_l:
            
          break;
          case SDLK_k:
          break;

          case SDLK_j:
          break;
          case SDLK_SEMICOLON:
          break;

          case SDLK_a:
            state = State::canvas;
          break;
      }
      switch(event.key.keysym.sym){
        case SDLK_f:
          if(fullscreen){
            SDL_SetWindowFullscreen(window, 0);
            fullscreen = 0;
          }
          else{
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            fullscreen = 1;
          }
        break;
      }
    }
  }
}

