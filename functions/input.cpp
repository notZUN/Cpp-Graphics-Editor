#include "../assets.h"
#include <SDL2/SDL.h>
#include<iostream>
#include<string>

void input(){
  const uint8_t* keystate = SDL_GetKeyboardState(NULL);
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT) running = false;
    if(event.type == SDL_KEYDOWN) 
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
        case SDLK_a:
          if(set_color){
            set_color = 0; 
          }
          else{
            set_color = 1;
            new_color_rgb[0] = 0;
            new_color_rgb[1] = 0;
            new_color_rgb[2] = 0;
          }
        break;
      }
    
  }
}

