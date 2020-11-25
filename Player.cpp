#include "Player.h"
#include "Animation.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(60.0f, 70.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(300.f, 250.f);
    body.setTexture(texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    velocity.x *= 0.0f;
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= speed;
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += speed;        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& canJump) 
    {
        canJump = false;
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
    }

    
    velocity.y += 981.0f * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && speedUp ||sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && speedUp)
    {
       speed = speed  +  200;
       speedUp = false;
    }
    else if(!speedUp)
    {
        speed = speed - 200;
        speedUp = true;
    }

    if (velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 1;
        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

    body.move(velocity*deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Player::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        velocity.x = 0.0f;
    }
    else if(direction.x > 0.0f)
    {
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        velocity.y = 0.0f;
    }
}

void Player::SetPosition(float x, float y)
{
    body.setPosition(x, y);
}

bool Player::getDirection()
{
    return faceRight;
}
