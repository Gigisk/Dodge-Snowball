#include "Button.h"
//constructor
Button::Button(float x1, float y1, float x2, float y2, float width, float height, String name_btn, Color idleColor, Color hoverColor, Color activeColor)
{
    //button state
    this->buttonState = BTN_IDLE;

    //button
    this->shape.setPosition(Vector2f(x1,y1));
    this->shape.setSize(Vector2f(width,height));

    //text
    this->font.loadFromFile("images/Chalkboard.ttc");
    this->text.setFont(font);
    this->text.setString(name_btn);
    this->text.setFillColor(Color::White);
    this->text.setCharacterSize(50);
    this->text.setPosition(Vector2f(x2,y2));
    
    //button condition
    this->idleColor=idleColor;
    this->hoverColor=hoverColor;
    this->activeColor=activeColor;

    this->shape.setFillColor(this->idleColor);
}
//destructor
Button::~Button()
{
}
//returns if button is pressed
const bool Button::isPressed() const
{
    if(this->buttonState == BTN_ACTIVE){
        return true;
    }
        
    return false;
}
//update
void Button::update(const Vector2f mousePos)
{
    //IDLE
    this->buttonState = BTN_IDLE;

    if(this->shape.getGlobalBounds().contains(mousePos)){
        
        //HOVER
        this->buttonState = BTN_HOVER;

        if(Mouse::isButtonPressed(Mouse::Left)){
            
            //ACTIVE
            this->buttonState = BTN_ACTIVE;
        }
    }
    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;
    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        break;
    default:
        this->shape.setFillColor(Color::Red);
        break;
    }

}
//render
void Button::render(RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->text);
}
