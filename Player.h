#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Player{
private:
    Texture forPlayer;
    Sprite playerImage;
    
    float movementSpeed;
    Vector2f playerPosition;
    void initVariables();
    void initShape();
public:
    Player();
    virtual ~Player();

    Sprite getPlayer();
    void setPLayerPosition();
    void upadateInput();
    void update(RenderTarget* target);
    void render(RenderTarget* target);
};