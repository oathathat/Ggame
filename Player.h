#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime, int hit);
    void Draw(sf::RenderWindow& window);
    void onCollision(sf::Vector2f direction);
    void SetPosition(float x, float y);
    void setHP(int x);
    void DecreaseHP(int x);
    void setLife(int x);
    void DecreaseLife(int x);
    int getHP();
    bool getDirection();
    int GetSpeed();
    int getLife();
    void setspawnX(float x);
    void setspawnY(float y);
    float getspawnX();
    float getspawnY();
    void spawn();




    sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    sf::RectangleShape body;


private:

    Animation animation;
    unsigned int row;
    unsigned int stop;
    float speed;
    bool faceRight;
    int HP;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    bool speedUp;
    int life;
    float spawnX;
    float spawnY;
    sf::SoundBuffer jumpBuff;
    sf::Sound jumpSound;
};