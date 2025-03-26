#include "Snowball.h"
using namespace sf;
//init snowball
void Snowball::initShape()
{
    this->forSnowball.loadFromFile("images/snowball.png");
    this->snowball.setTexture(forSnowball);
}
//constructor
Snowball::Snowball()
{

    float X1 = 2360.0f;
	float Y1 = 300.0f;
	float X2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X1));
	float Y2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/Y1));
	this->snowball.setPosition(X2,Y2);
    this->initShape();
}
//destructor
Snowball::~Snowball()
{

}
//get snowball
Sprite Snowball::getSnowball()
{
    return Sprite(snowball);
}
//render
void Snowball::render(RenderTarget *target)
{
    target->draw(this->snowball);
}
