#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(position)) {
		body.setPosition(position);
	}
private:
	sf::RectangleShape body;
	sf::RectangleShape texture;
	Animation animation;
	unsigned int row;
	sf::Vector2f velocity;
};

