#ifndef ASSETS_H
#define ASSETS_H
#include <cstdint>
#include <string>
#include <SDL2/SDL.h>
#include <vector>

//class 

//arrays & variables
extern SDL_Window* window;
extern SDL_Event event;
extern SDL_Renderer* render;
extern SDL_Texture* texture;
constexpr short window_height = 480, window_width = 640;
extern std::vector<uint16_t> pallete;
extern bool running;
extern uint8_t screen[window_width * window_height];
extern uint16_t final_screen[window_width * window_height];
extern const bool font[26][65];

//functions
extern void input();
extern void camera_paint();
extern void camera_conversion();
extern void text(std::string s, short x, short y, uint8_t col, uint8_t size);

#endif
