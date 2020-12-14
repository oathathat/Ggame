#include "difficult.h"

difficult::difficult(float width, float height)
{
	move.loadFromFile("resource/menumove.wav");
	moveSound.setBuffer(move);
	moveSound.setVolume(40.0);

	select.loadFromFile("resource/menuselect.wav");
	selectSound.setBuffer(select);
	selectSound.setVolume(40.0);

	font.loadFromFile("resource/lady.ttf");

	Difficult[0].setFont(font);
	Difficult[0].setFillColor(sf::Color::Red);
	Difficult[0].setString("Easy");
	Difficult[0].setPosition(sf::Vector2f(width / 2-30, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	Difficult[1].setFont(font);
	Difficult[1].setFillColor(sf::Color::White);
	Difficult[1].setString("Normal");
	Difficult[1].setPosition(sf::Vector2f(width / 2-58, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	Difficult[2].setFont(font);
	Difficult[2].setFillColor(sf::Color::White);
	Difficult[2].setString("Hard");
	Difficult[2].setPosition(sf::Vector2f(width / 2-30, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

difficult::~difficult()
{

}
void difficult::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Difficult[i]);
	}
}
void difficult::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		moveSound.play();
		Difficult[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		Difficult[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void difficult::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		moveSound.play();
		Difficult[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		Difficult[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}