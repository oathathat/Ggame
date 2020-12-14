#include "winMenu.h"

winMenu::winMenu(float width, float height)
{
	move.loadFromFile("resource/menumove.wav");
	moveSound.setBuffer(move);
	moveSound.setVolume(40.0);

	select.loadFromFile("resource/wining.wav");
	selectSound.setBuffer(select);
	selectSound.setVolume(40.0);
	font.loadFromFile("resource/lady.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("MainMenu");
	menu[0].setPosition(sf::Vector2f(width / 2-90, height / (MAX_NUMBER_OF_ITEMS + 1) * 1-50));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SCoreboard");
	menu[1].setPosition(sf::Vector2f(width / 2-105, height / (MAX_NUMBER_OF_ITEMS + 1) * 2-50));

	selectedItemIndex = 0;
}

winMenu::~winMenu()
{
}

void winMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void winMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

void winMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
