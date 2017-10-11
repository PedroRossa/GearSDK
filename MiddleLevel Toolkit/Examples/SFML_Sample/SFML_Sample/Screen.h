#pragma once
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Screen
{
public:
	Screen();
	~Screen();

	sf::RenderWindow* window;

	sf::Font* font;

	sf::Text txtAccelerometer;
	sf::Text txtGyro;
	sf::Text txtAngle;
	sf::Text txtButton;
	sf::Text txtPotentiometer;

	sf::CircleShape spLed;

	void WindowUpdate();
};

