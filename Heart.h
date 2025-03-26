#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;
class Heart{
private:
    Texture heart;
    void initShape();

public:
    Sprite heart1;
    Sprite heart2;
    Sprite heart3;
    
    Heart();
    virtual ~Heart();

    //functions
    void setAllHeartPositions();
    void render(RenderTarget* target);
};
