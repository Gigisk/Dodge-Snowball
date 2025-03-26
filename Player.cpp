#include "Player.h"
using namespace sf;
//init speed
void Player::initVariables()
{
    this->movementSpeed=10;
}
//init shape
void Player::initShape()
{
    this->forPlayer.loadFromFile("images/penguin.png");
    this->playerImage.setTexture(forPlayer);
}
//constructor
Player::Player()
{
    this->playerPosition.x=1180;
    this->playerPosition.y=850;
    this->playerImage.setPosition(playerPosition);
    this->initVariables();
    this->initShape();
}
//destructor
Player::~Player()
{

}
//gets player
Sprite Player::getPlayer()
{
    return Sprite(playerImage);
}
//sets player position
void Player::setPLayerPosition()
{
    this->playerPosition.x=1180;
    this->playerPosition.y=850;
    this->playerImage.setPosition(playerPosition);
}
//moving events
void Player::upadateInput()
{
    //keyboard input
    if(Keyboard::isKeyPressed(Keyboard::A)){
        this->playerPosition.x -= movementSpeed; 
        if(this->playerPosition.x <= 0 ) this->playerPosition.x += movementSpeed;
    }
    else if(Keyboard::isKeyPressed(Keyboard::D)){
        this->playerPosition.x += movementSpeed; 
        if(this->playerPosition.x > 2360 ) this->playerPosition.x -= movementSpeed;
    }
    this->playerImage.setPosition(playerPosition);
}
//update
void Player::update(RenderTarget* target)
{
    this->upadateInput();   
}
//render
void Player::render(RenderTarget *target)
{
    target->draw(this->playerImage);
}
