#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include "Player.h"
#include<SFML/Audio.hpp>
class Item
{
public:
	Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,sf::Vector2f position);
	~Item();
		
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private:
	
	Animation animation;
	float SizeX;
	float SizeY;
	int animationFrame = 0;
	sf::RectangleShape body;
	sf::RectangleShape texture;
	unsigned int row = 0;

	
};

