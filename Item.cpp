#include "Item.h"
#include<SFML/Graphics.hpp>
#include"Collider.h"


Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	
    body.setPosition(position);
    body.setSize(sf::Vector2f(50.f,50.f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(1.0, 1.0);
    body.setTexture(texture);       
}

Item::~Item()
{
}


void Item::Update(float deltaTime)
{
    row = 0;
    body.setTextureRect(animation.uvRect);
    animation.Update(row, deltaTime, true);    
}

void Item::Draw(sf::RenderWindow& window)
{
    window.draw(this->body);
}
