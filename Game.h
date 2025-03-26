#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Snowball.h"
#include "Heart.h"
#include "Button.h"


using namespace std;
using namespace sf;

enum player_condition{DEAD=0,ALIVE};
class Game{
private:
    short unsigned playerCondition;
    //window
    RenderWindow* window;
    VideoMode videomode;
    Event event;
    // game icon
    Image icon;
    //game objects

    Texture gameover;
    Sprite gameoverBackground;

    Texture background;
    Sprite backgroundImage;
    
    Snowball snowball;
    vector<Sprite> snowballs;
    Clock add;
    
    Player player;

    Heart heart;

    Button* yes_btn;
    Button* no_btn;

    Clock Fast;
    double snowballsFallingSpeed;
    int health;

    bool disposable;
    //private functions
    void initializeVariable();
    void initWindow();
    void initBackground();
    void initIcon();
    void reset();
protected:
    Vector2i mousePosScreen;
    Vector2i mousePosSWindow;
    Vector2f mousePosView;
public:
    //constructor / destructor
    Game();
    virtual ~Game();

    virtual void updateMousePosition();
    
    //Accessors
    const bool running() const;
    //functions
    void snowballUpdate();
    void pollEvents();
    void update();
    void render();
    
};