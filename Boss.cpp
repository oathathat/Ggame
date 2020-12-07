#include "Boss.h"
#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position):
	animation(texture, imageCount, switchTime)
{
    //this->initTexture();
    this->speed = speed;
    row = 0;
    faceRight = true;

    this->hp = 10;

    body.setSize(sf::Vector2f(80, 80));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(2.0, 2.0);
    body.setTexture(texture);
    body.setPosition(position);
}

Boss::~Boss()
{
}

void Boss::setHP(int x)
{
    this->hp -= x;
}

int Boss::getHP()
{
    return this->hp;
}

void Boss::Update(float deltaTime, Player* player)
{       
    //velocity.x *= 0.0f;
    if (player->GetPosition().x + 500 > body.getPosition().x)
    {
        if (body.getPosition().x>player->GetPosition().x)
        {
            velocity.x = -speed;            
        }
        else if (body.getPosition().x < player->GetPosition().x)
        {
            velocity.x = speed;            
        }
    }



    //   for (auto* bullet : bullets)
    //   {
    //    if (player->GetGlobalBounds().intersects(bullet->GetGlobalBounds()))
    //    {
    //       bullet->setPosition(-50.0f, -50.0f);
    //    }
    //   }

    if (velocity.x != 0.0f)
    {
        row = 0;
        if (velocity.x > 0.0f)
            faceRight = false;
        else
            faceRight = true;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);


    body.move(velocity * deltaTime);
}

void Boss::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Boss::onCollision(sf::Vector2f direction)
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

void Boss::setPosition(float x, float y)
{
    body.setPosition(x, y);
}
