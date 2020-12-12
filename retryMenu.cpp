#include "retryMenu.h"

retryMenu::retryMenu(float width, float height)
{
	move.loadFromFile("resource/menumove.wav");
	moveSound.setBuffer(move);
	moveSound.setVolume(40.0);

	select.loadFromFile("resource/menuselect.wav");
	selectSound.setBuffer(select);
	selectSound.setVolume(40.0);
	font.loadFromFile("resource/lady.ttf");
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Try Again");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Main Menu");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;

	
}

retryMenu::~retryMenu()
{

}
void retryMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void retryMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void retryMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}