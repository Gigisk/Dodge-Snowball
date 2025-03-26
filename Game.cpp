#include "Game.h"

using namespace std;
using namespace sf;
//int variables
void Game::initializeVariable()
{
    this->window=nullptr;
    this->snowballsFallingSpeed=4;
    this->health=3;
	this->playerCondition=ALIVE;
	this->disposable=false;
}
// window
void Game::initWindow()
{
    this->videomode.width=2560;
    this->videomode.height=1280;
    this->window= new RenderWindow(this->videomode, "Snowball Dodge!");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(true);
}
//game icon
void Game::initIcon()
{
    this->icon.loadFromFile("images/Snowball Dodge icon.png");
}
//reset objects to default positions
void Game::reset()
{
	//snowballs
	snowballs.resize(10);
	for(int i=0; i<snowballs.size(); i++){
		float X1 = 2360.0f;
		float Y1 = 300.0f;
		float X2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X1));
		float Y2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/Y1));
		this->snowballs[i].setPosition(X2,Y2);
	}
	//hearts
	this->heart.setAllHeartPositions();
	//player
	this->player.setPLayerPosition();
	//snowball falling speed and timer
	this->snowballsFallingSpeed=4;
	this->Fast.restart();
	this->add.restart();
	//health
	this->health = 3;
	//condition
	this->playerCondition=ALIVE;
	
}
// backgroud
void Game::initBackground()
{
    //main background
	this->background.loadFromFile("images/background.jpeg");
    this->backgroundImage.setTexture(background);

	//game over background
	this->gameover.loadFromFile("images/gameover.jpg");
    this->gameoverBackground.setTexture(gameover);
}
//constructor
Game::Game()
{
  	//setting
	this->initializeVariable();
    this->initWindow(); 
    this->initBackground();
    this->initIcon();

	//buttons
	this->yes_btn = new Button(990,900,1000,900,90,60,"Yes",Color(70,70,70,100),Color(150,150,150,255),Color::Green);
	this->no_btn = new Button(1390,900,1400,900,80,60,"No",Color(70,70,70,200),Color(150,150,150,255),Color::Red);
}
//destructor
Game::~Game(){
    //delete
	delete this->window;
	delete this->yes_btn;
	delete this->no_btn;
}
//updating mouse position
void Game::updateMousePosition()
{
	this->mousePosScreen = Mouse::getPosition();
    this->mousePosSWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}
//returning window (while window is open)
const bool Game::running() const
{
    return this->window->isOpen();
}
//update snowballs
void Game::snowballUpdate()
{
	//adds 10 snowballs from start at random positions , using only once
	if(!this->disposable){
		for(int i=0; i<10; i++){
			this->snowballs.push_back(snowball.getSnowball());
			float X1 = 2360.0f;
			float Y1 = 300.0f;
			float X2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X1));
			float Y2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/Y1));
			this->snowballs[i].setPosition(X2,Y2);
		}
		this->disposable=true;
	}

	for(int i=0; i<snowballs.size(); i++){
		//if snowball hits the ground, snowball's position updates on top
		if(this->snowballs[i].getPosition().y >= 1030)
    	{
        	float X1 = 2360.0f;
			float X2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X1));
			this->snowballs[i].setPosition(X2,0.f);
    	}
		//if snowball hits player 
    	else if(this->snowballs[i].getGlobalBounds().intersects(this->player.getPlayer().getGlobalBounds()))
		{
			float X = 2360.0f;
			float r = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
			//heart dissappears
			if(health == 3){
				health--;
				this->heart.heart3.setPosition(-1000.0f, -1000.0f);
			}
			else if(health == 2){
				health--;
				this->heart.heart2.setPosition(-1000.0f, -1000.0f);
			}
			//if last heart dissapears
			else if(health ==1){
			health--;
			this->heart.heart1.setPosition(-1000.0f, -1000.0f);
			//player assumes as dead
			this->playerCondition=DEAD;
		}
		//snowball's position updates on top 
		this->snowballs[i].setPosition(r,0.f);
	}
		else
		{
			//if player isn't dead snowball's speed doubles every 15 seconds 
			if(Fast.getElapsedTime().asSeconds() > 15.0f && health!=0){
				this->snowballsFallingSpeed+=2;
				Fast.restart();
	   		}
			//if player isn't dead vector adds new snowball every 15 seconds 
			if(add.getElapsedTime().asSeconds() > 7.0f && health!=0){
				float X1 = 2360.0f;
				float X2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X1));
				this->snowballs.push_back(snowball.getSnowball());
				this->snowballs[snowballs.size()-1].setPosition(X2,0.f);
				add.restart();
	   		}
			//if player isn't dead snowball falls
			else if(health!=0){
				this->snowballs[i].move(Vector2f(0,snowballsFallingSpeed));
			}
		}
	}
	
}
//game closing inputs
void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
    {
        if (event.type == Event::Closed) this->window->close();
        else if (Keyboard::isKeyPressed(Keyboard::Escape)) this->window->close();
    }

}
//update
void Game::update()
{
    this->pollEvents();
    this->player.update(this->window);
	this->snowballUpdate();
	this->updateMousePosition();
	this->yes_btn->update(this->mousePosView);
	this->no_btn->update(this->mousePosView);
}
//rendering game
void Game::render(){
    this->window->clear();  
    //draw game objects

    // background
    this->window->draw(this->backgroundImage); 
    // player
    this->player.render(this->window); 
    //snowball
	for(int i=0; i<snowballs.size(); i++){
		this->window->draw(this->snowballs[i]);
	}
    //heart
    this->heart.render(this->window);
	//if player dies
	if(this->playerCondition==DEAD){
		this->window->clear();
		this->window->draw(this->gameoverBackground);
		this->yes_btn->render(this->window);
		this->no_btn->render(this->window);
		if(this->no_btn->isPressed()){
			this->window->close();
		}
		else if(this->yes_btn->isPressed()){
			this->reset();
		}
	}
    //display
    this->window->display();
    this->window->setIcon(icon.getSize().x, icon.getSize().y,  icon.getPixelsPtr());
}

