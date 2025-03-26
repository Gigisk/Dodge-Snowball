#include "Heart.h"
//init shape
void Heart::initShape()
{
    this->heart.loadFromFile("images/heart.png");
    this->heart1.setTexture(heart);
    this->heart2.setTexture(heart);
    this->heart3.setTexture(heart);
}
//constructor
Heart::Heart()
{
    this->heart1.setPosition(0,1150);
    this->heart2.setPosition(120,1150);
    this->heart3.setPosition(240,1150);
    this->initShape();
}
//destructor
Heart::~Heart()
{
}
//set hearts positions
void Heart::setAllHeartPositions()
{
    this->heart1.setPosition(0,1150);
    this->heart2.setPosition(120,1150);
    this->heart3.setPosition(240,1150);
}
//render
void Heart::render(RenderTarget *target)
{
    target->draw(this->heart1);
    target->draw(this->heart2);
    target->draw(this->heart3);
}
