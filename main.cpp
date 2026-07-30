#include "assets.h"
#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>

SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
SDL_Texture* texture = nullptr;
bool running = true;
std::pair<bool, uint8_t> screen[window_width * window_height];
uint16_t final_screen[window_width * window_height];
SDL_Event event;
bool fullscreen = 0;
State state = State::canvas;
uint16_t new_color_rgb[3];
std::vector<uint16_t> colors = {
  0,
  65535,
  31,
  2047,
  65504,
  1248,
  31296,
  27264,
  29408
};
uint16_t select_color = 0;

int canvas_size_x = 15;
int canvas_size_y = 10;
std::vector<uint16_t> canvas = {
  2,2,1,2,2,2,2,2,2,2,2,2,2,4,4,
  2,1,1,1,2,2,2,2,2,2,1,2,2,4,4,
  2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,
  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
  2,2,2,2,2,8,8,8,8,8,2,2,2,2,2,
  2,2,5,2,8,8,8,8,8,8,8,2,2,2,2,
  2,5,5,5,2,6,6,6,6,6,2,2,2,2,2,
  2,2,6,2,2,6,3,6,8,6,2,2,2,2,2,
  2,2,6,2,2,6,6,6,8,6,2,2,2,2,2,
  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
};
int set = 0;
int canvas_set_x = 0, canvas_set_y = 0;

int main(int argc, char* argv[]){
    const uint8_t* keystate = SDL_GetKeyboardState(NULL);

    if(SDL_Init(SDL_INIT_VIDEO) < 0 || SDL_Init(SDL_INIT_AUDIO)){
      std::cout << "Error: " << SDL_GetError() << '\n';
      return 1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    //create window
    window = SDL_CreateWindow(
        "CGE",
        100, 
        100, 
        window_width, 
        window_height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if(window == nullptr){
      std::cout << "Error: " << SDL_GetError() << '\n';
      return 1;
    }

    render = SDL_CreateRenderer(window, -1, 0);
    if(render == nullptr){
      std::cout << "Error: " << SDL_GetError() << '\n';
      return 1;
    }
    SDL_RenderSetLogicalSize(render, window_width, window_height);

    //create texture
    texture = SDL_CreateTexture(
      render,
      SDL_PIXELFORMAT_RGB565,
      SDL_TEXTUREACCESS_STREAMING,
      window_width, window_height
    );
    if(texture == nullptr){
      std::cout << "Error: " << SDL_GetError() << '\n';
      return 1;
    }

    //cleaning array of camera
    for(uint16_t i = 0; i < window_height; i++){
        for(uint16_t j = 0; j < window_width; j++){
        screen[i*window_width+j].first = 1;
        screen[i*window_width+j].second = 0;
      }
    }

//game
  while(running){
    SDL_RenderClear(render);
        
  //input
    input();
        
  //painting&conversion
    screen_paint();

    screen_conversion();

        
    SDL_UpdateTexture(texture, NULL, final_screen, window_width * sizeof(short));
    SDL_RenderCopy(render, texture, NULL, NULL);
    SDL_RenderPresent(render);
       
  //errors 
    if(texture == nullptr || render == nullptr || window == nullptr){
      std::cout << "Error: " << SDL_GetError() << '\n';
      return 1;
    }
  }

  //end 
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(render);

  SDL_Quit();

  return 0;
}
