#include "includes.h"

class uielement {
  public:
    SDL_Rect coords;
    SDL_Renderer* renderer;
};

class button:uielement {
  public:
    string text, hint;
    SDL_Color color, bordercolor;
  void draw();
};

class label:uielement {
  public:
    string text;
    SDL_Color color;
  void draw();
};

class textfield:uielement {
  public:
    string text, hint, deftext;
    SDL_Color color, bordercolor, bgcolor;
  void draw();
};

class uisystem {
  std::vector<button> buttons;
  std::vector<label> labels;
  std::vector<textfield> textfields;
  SDL_Renderer* renderer;
public:
  void addbutton(int x, int y, int w, int h, string text, string hint, SDL_Color color, SDL_Color bordercolor);
  void drawall();
};