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

class Instructions_State : public Widget_Gamestate {
  Instructions_State(const Instructions_State &);
  Instructions_State operator=(const Instructions_State &);

  public:
    Instructions_State()
      : Widget_Gamestate(make_pair(Point2f(0.0f, 0.0f), Point2f(800.0f, 600.0f)))
    {
    }

  private:
    void on_key(const SDL_KeyboardEvent &event) {
      if(event.keysym.sym == SDLK_ESCAPE && event.state == SDL_PRESSED)
        get_Game().pop_state();
    }

    void render() {
      Widget_Gamestate::render();

      Zeni::Font &fr = get_Fonts()["title"];

      fr.render_text(
#if defined(_WINDOWS)
                     "ALT+F4"
#elif defined(_MACOSX)
                     "Apple+Q"
#else
                     "Ctrl+Q"
#endif
                     " to Quit",
                     Point2f(400.0f, 300.0f - 0.5f * fr.get_text_height()),
                     get_Colors()["title_text"],
                     ZENI_CENTER);
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
