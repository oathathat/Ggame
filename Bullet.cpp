#include "Bullet.h"
#include <iostream>
#include "Enemy.h"

Bullet::Bullet(sf::Texture* texture, float speed, float posx, float posy, float dirx, float diry)

{
    SizeX = texture->getSize().x / 4;
    SizeY = texture->getSize().y / 2;
    this->speed = speed;
    body.setSize(sf::Vector2f(423/30*4, 110/20*4));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(1.0, 1.0);
    body.setTexture(texture);
    body.setPosition(posx, posy);
    body.setTextureRect(sf::IntRect(0,0,SizeX,SizeY));
    this->direction.x = dirx;
    this->direction.y = diry;

}
Bullet::~Bullet()
{

}

void Bullet::Update()
{
    this->body.move(this->direction * this->speed);    
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(this->body);
}

void Bullet::bulletDirection(bool playerDirection)
{
    if (playerDirection)
    {
        body.setTextureRect(sf::IntRect(SizeX * animationFrame, SizeY * 1, SizeX, SizeY));
    }
    else 
    {
        body.setTextureRect(sf::IntRect(SizeX * animationFrame, SizeY * 0, SizeX, SizeY));
    }
    animationFrame++;

    if (animationFrame >= 3) {
        animationFrame = 0;
    }
}



void Bullet::setPosition(float x, float y)
{
    body.setPosition(x, y);
}
