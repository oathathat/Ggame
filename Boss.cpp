#include "Boss.h"
#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position) :
    animation(texture, imageCount, switchTime)
{

    this->speed = speed;
    row = 0;
    faceRight = true;
    this->goback = 0;
    this->hp = 10;

    body.setSize(sf::Vector2f(80, 80));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(2.0, 2.0);
    body.setTexture(texture);
    body.setPosition(position);
    this->spawnX = body.getPosition().x;
    this->spawnY = body.getPosition().y;
    bossCbuff.loadFromFile("resource/Inception.wav");
    bosscounterSound.setBuffer(bossCbuff);
    bosscounterSound.setVolume(30.0);
}

Boss::~Boss()
{
}

void Boss::DecreaseHP(int x)
{
    this->hp -= x;
}

int Boss::getHP()
{
    return this->hp;
}

void Boss::Update(float deltaTime, Player* player)
{
    if (body.getPosition().x <= spawnX - 500)
    {
        velocity.x = speed;
        goback = 1;
    }
    if (body.getPosition().x >= spawnX + 500)
    {
        velocity.x = -speed;
        goback = 1;
    }
    if (player->GetPosition().x + 500 > body.getPosition().x && body.getPosition().x >= spawnX - 500 && goback == 0)
    {
        if (body.getPosition().x > player->GetPosition().x)
        {
            velocity.x = -speed;
        }
        else if (body.getPosition().x < player->GetPosition().x)
        {
            velocity.x = speed;
        }
    }

    if (body.getPosition().x >= player->GetPosition().x + 500 && player->getLife() < -1)
    {
        bosscounterSound.play();
    }

    if (player->GetPosition().x + 600 < body.getPosition().x && goback == 1) {
        goback = 0;
        body.setPosition(spawnX, spawnY);
        velocity.x = 0;
    }
    if (player->GetPosition().x - 600 > body.getPosition().x && goback == 1) {
        goback = 0;
        body.setPosition(spawnX, spawnY);
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