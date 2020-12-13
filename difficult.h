#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
#include<SFML/Audio.hpp>
class difficult
{
public:
	difficult(float width, float height);
	~difficult();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { selectSound.play(); return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text Difficult[MAX_NUMBER_OF_ITEMS];
	sf::SoundBuffer move, select;
	sf::Sound moveSound, selectSound;

};

