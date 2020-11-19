#include "Bullet.h"
Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(sf::Vector2f(10.0f, 10.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

void Bullet::Update(float deltatime)
{
	velocity.x = 500.0f;
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltatime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}