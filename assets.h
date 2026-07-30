#ifndef ASSETS_H
#define ASSETS_H
#include <cstdint>
#include <string>
#include <SDL2/SDL.h>
#include <vector>

//class 
enum class State {
  canvas,
  new_color,
  size
};

//arrays & variables
extern SDL_Window* window;
extern SDL_Event event;
extern SDL_Renderer* render;
extern SDL_Texture* texture;
constexpr short window_height = 360, window_width = 640;
extern std::vector<uint16_t> pallete;
extern bool running;
extern std::pair<bool, uint8_t> screen[window_width * window_height];
extern uint16_t final_screen[window_width * window_height];
extern const bool font[26][65];
extern bool fullscreen;
extern State state;
extern int canvas_size_x;
extern int canvas_size_y;
extern std::vector<uint16_t> canvas;
extern std::vector<uint16_t> colors;
extern uint16_t new_color_rgb[3];
extern const bool font_num[10][65];
extern uint16_t select_color;
extern int set;
extern int canvas_set_x, canvas_set_y;

//functions
extern void input();
extern void screen_paint();
extern void screen_conversion();
extern void text(std::string s, short x, short y, uint8_t col, uint8_t size);
extern void save();
extern void canvas_resize();

#endif
