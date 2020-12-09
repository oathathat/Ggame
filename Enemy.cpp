#include "Enemy.h"
#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position) :
    animation(texture, imageCount, switchTime)
{    
    this->speed = speed;
    row = 0;
    faceRight = true;

    this->hp = 3;

    body.setSize(sf::Vector2f(80, 80));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(1.0, 1.0);  
    body.setTexture(texture);
    body.setPosition(position);

    this->spawnX = body.getPosition().x;
   
  
    //Sound
    /*soundJump.loadFromFile("JumpSOUND.wav");
    sJump.setBuffer(soundJump);
    sJump.setVolume(15.0);
    */

}

Enemy::~Enemy()
{
   
}

void Enemy::DecreaseHP(int x)
{
    this->hp -= x;
}

int Enemy::getHP()
{
    return this->hp;
}

void Enemy::Update(float deltaTime, Player* player)
{
    MoveClock.getElapsedTime().asSeconds();
     int r = rand() % 2;   
   
    if (player->GetPosition().x + 500 >= body.getPosition().x && body.getPosition().x >= spawnX - 250 && body.getPosition().x <= spawnX+250)
    {
        if    (r <= 0 && MoveClock.getElapsedTime().asSeconds()>1 )
        {
            velocity.x = speed;
            MoveClock.restart();
        
        }
        else if (r >= 1 && MoveClock.getElapsedTime().asSeconds() > 1 )
        {
            velocity.x = -speed;
            MoveClock.restart();
        }       
    }
    else if (body.getPosition().x <= spawnX - 250)
    {
        velocity.x = speed;
        MoveClock.restart();
    }
    else if (body.getPosition().x >= spawnX + 250)
    {
        velocity.x = -speed;
        MoveClock.restart();
    }
    else 
    {
        velocity.x = 0;      
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


void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(body);
  
}


void Enemy::onCollision(sf::Vector2f direction)
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

void Enemy::setPosition(float x, float y)
{
    body.setPosition(x, y);
}

