#include "Player.h"
#include "Animation.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    this->HP = 100;
    this->row = row;
    this->spawnX = 510.f;
    this->spawnY = 240.f;
    this->life = 3;

    faceRight = true;

    body.setSize(sf::Vector2f(64.0f, 64.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(300.f, 250.f);
    body.setTexture(texture);
    jumpBuff.loadFromFile("resource/jump.wav");
    jumpSound.setBuffer(jumpBuff);
    jumpSound.setVolume(30.0);
}

Player::~Player()
{

}

void Player::Update(float deltaTime, int hit)
{
    velocity.x *= 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= speed *deltaTime*120.0f;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += speed * deltaTime*120.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && speedUp || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && speedUp)
    {
        speed = speed + 110;
        jumpHeight = jumpHeight + 90;
        speedUp = false;
    }
    else if (!speedUp)
    {
        speed = speed - 110;
        jumpHeight = jumpHeight - 90;
        speedUp = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump && velocity.y <= 0)
    {
        jumpSound.play();
        canJump = false;
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight*1.2)-100;
    }


    velocity.y += 981.0f * deltaTime*1.2;

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        row = 2;
    }

    if (hit == 1)
    {
        if (faceRight)
        {
            velocity.x -= speed * deltaTime * 180.0f+200;
            row = 3;
        }
        else
        {
            velocity.x += speed * deltaTime * 180.0f+200;
            row = 3;
        }
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
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
    else if (direction.x > 0.0f)
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

void Player::setHP(int x)
{
    this->HP = x;
}


void Player::DecreaseHP(int x)
{
    this->HP -= x;
}

void Player::setLife(int x)
{
    this->life = x;
}

void Player::DecreaseLife(int x)
{
    this->life -= x;
}



int Player::getHP()
{
    return this->HP;
}

bool Player::getDirection()
{
    return faceRight;
}

int Player::GetSpeed()
{
    return this->speed;
}

int Player::getLife()
{
    return this->life;
}

void Player::setspawnX(float x)
{
    this->spawnX = x;
}

void Player::setspawnY(float y)
{
    this->spawnY = y;
}


float Player::getspawnX()
{
    return this->spawnX;
}

float Player::getspawnY()
{
    return this->spawnY;
}

void Player::spawn()
{
    body.setPosition(this->spawnX, this->spawnY);
}


