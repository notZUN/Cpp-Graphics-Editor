#include "lang.h"
#include<string>

Language lang = Language::EN;

const std::string text[(int)Language::COUNT][(int)Txt::COUNT] = {
  {
  
  }
};

std::string get_text(Txt id){
  return text[(int)lang][(int)id];
}
