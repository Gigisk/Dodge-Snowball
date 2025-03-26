#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;
class Snowball{
private:
    Texture forSnowball;
    Sprite snowball;
    //init
    void initShape();
public:
    
    Snowball();
    virtual ~Snowball();

    //functions
    Sprite getSnowball();
    void render(RenderTarget* target);
};