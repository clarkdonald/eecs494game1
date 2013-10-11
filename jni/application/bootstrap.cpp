 /* This file is part of the Zenipex Library (zenilib).
 * Copyleft (C) 2011 Mitchell Keith Bloch (bazald).
 *
 */

#include <zenilib.h>
#include "Includes.h"

#if defined(_DEBUG) && defined(_WINDOWS)
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using namespace std;
using namespace Zeni;

class Instructions_State : public Gamestate_Base {
  Text_Box tb;

  public:
    Instructions_State()
    : tb(Point2f(),
         Point2f(800.0f, 600.0f),
         "system_36_800x600",
         "P U R P O S E\n"
         "The point of the game is to get to safety by getting to your airplane. "
         "You do this by clearing obstacles in the map you are thrown in. "
         "Play to learn more!\n\n"
         "C O N T R O L S\n"
         "Arrow Keys: Move the explorer\n"
         "S Key: Pick up an item\n"
         "D Key: Drop an item\n"
         "F Key: Use an item\n"
         "Space Bar: Move the explorer faster\n\n"
         "P Key: Retry level\n"
         "ESC to return to the menu.",
         Color())
    {
      tb.give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
    }

  private:
    void on_key(const SDL_KeyboardEvent &event) {
      if(event.keysym.sym == SDLK_ESCAPE) {
        if(event.state == SDL_PRESSED)
          get_Game().pop_state();
      }
    }

    void render() {
      get_Video().set_2d(make_pair(Point2f(), Point2f(800.0f, 600.0f)), true);
      tb.render();
    }
};

class Title_State_Custom : public Title_State<Play_State, Instructions_State> {
  public:
    Title_State_Custom()
    : Title_State<Play_State, Instructions_State>("")
    {
      m_widgets.unlend_Widget(title);
    }

    void render() {
      Title_State<Play_State, Instructions_State>::render();
      render_image("logo", Point2f(150.0f, 0.0f), Point2f(650.0f, 225.0f));
    }
};

class Bootstrap {
  class Gamestate_One_Initializer : public Gamestate_Zero_Initializer {
    virtual Gamestate_Base * operator()() {
      Window::set_title("Explorer");
      get_Joysticks();
      get_Video();
      get_Textures();
      get_Fonts();
      get_Sounds();
      get_Game().joy_mouse.enabled = true;
      return new Title_State_Custom;
    }
  } m_goi;

  public:
    Bootstrap() {
      g_gzi = &m_goi;
    }
} g_bootstrap;

int main(int argc, char **argv) {
  return zenilib_main(argc, argv);
}
