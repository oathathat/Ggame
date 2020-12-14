#include "Menu.h"

Menu::Menu(float width, float height)
{
	move.loadFromFile("resource/menumove.wav");
	moveSound.setBuffer(move);
	moveSound.setVolume(40.0);

	select.loadFromFile("resource/menuselect.wav");
	selectSound.setBuffer(select);
	selectSound.setVolume(40.0);	

	font.loadFromFile("resource/lady.ttf");
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2-35, height / (MAX_NUMBER_OF_ITEMS + 1) * 1+200));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SCore Board");
	menu[1].setPosition(sf::Vector2f(width / 2-100, height / (MAX_NUMBER_OF_ITEMS + 1) * 2+100));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2-15, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}