#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include<SFML/Audio.hpp>

class Bullet
{
public:
	Bullet(sf::Texture* texture, float speed, float posx, float posy, float dirx, float diry,float scaleX, float scaleY);
	~Bullet();	
	void setPosition(float x, float y);

	void Update();
	void Draw(sf::RenderWindow& window);
	void bulletDirection(bool playerDirection);
	void SetScale(float x, float y);


	sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }


private:
	float speed;
	float SizeX;
	float SizeY;
	int animationFrame = 0;
	sf::RectangleShape body;
	sf::RectangleShape texture;	
	sf::Vector2f velocity;
	sf::Vector2f direction;
};

