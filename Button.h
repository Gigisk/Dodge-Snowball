#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

enum button_states{BTN_IDLE = 0,BTN_HOVER,BTN_ACTIVE};
class Button{
private:
    short unsigned buttonState;

    Text text;
    RectangleShape shape;
    Font font;

    Color idleColor;
    Color hoverColor;
    Color activeColor;

public:
    //constructor-destructor
    Button(float x1, float y1, float x2, float y2, float width, float height, String name_btn,  Color idleColor, Color hoverColor, Color activeColor);
    virtual ~Button();
    
    //accessors
    const bool isPressed() const;

    //funcs
    void update(const Vector2f mousePos);
    void render(RenderTarget* target);
};