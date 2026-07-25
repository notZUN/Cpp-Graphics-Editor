#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include <string>

enum class Language {
    EN,
    COUNT
};

enum class Txt {
  
  COUNT
};

extern Language current_lang;

std::string get_text(Txt id);

#endif

