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
        case SDLK_z:

        break;
      }
  }
}

