#include "Screen.h"

Screen::Screen()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "GearSDK Sample");

	this->spLed.setRadius(40);

	this->font = new sf::Font();

	if (!this->font->loadFromFile("Resources/Fonts/calibri.ttf"))
	{
		printf("Error on load the font");
	}


	this->txtAccelerometer.setFont(*this->font);
	this->txtGyro.setFont(*this->font);
	this->txtAngle.setFont(*this->font);

	this->txtButton.setFont(*this->font);
	this->txtPotentiometer.setFont(*this->font);

	this->txtAccelerometer.setString("Accel: 0,0,0");
	this->txtGyro.setString("Gyro: 0,0,0");
	this->txtAngle.setString("Angle: 0,0,0");

	this->txtButton.setString("Button: false");
	this->txtPotentiometer.setString("Pot: 0");
	
	this->spLed.setPosition(sf::Vector2f(10, 10));

	this->txtAccelerometer.setPosition(sf::Vector2f(10, 120));
	this->txtGyro.setPosition(sf::Vector2f(10, 160));
	this->txtAngle.setPosition(sf::Vector2f(10, 200));

	this->txtButton.setPosition(sf::Vector2f(10, 240));
	this->txtPotentiometer.setPosition(sf::Vector2f(10, 280));
}

Screen::~Screen()
{
}

void Screen::WindowUpdate()
{
	this->window->clear();

	this->window->draw(this->txtAccelerometer);
	this->window->draw(this->txtGyro);
	this->window->draw(this->txtAngle);

	this->window->draw(this->txtButton);
	this->window->draw(this->txtPotentiometer);
	this->window->draw(this->spLed);

	this->window->display();
}
