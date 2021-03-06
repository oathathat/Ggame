#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <vector>
#include "Player.h"
#include<time.h>


class Enemy
{
public:
    Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
    ~Enemy();

    void DecreaseHP(int x);
    int getHP();

    void Update(float deltatime, Player* player);
    void Draw(sf::RenderWindow& window);       
    void onCollision(sf::Vector2f direction);
    void setPosition(float x, float y);
    int getATK();

    
    sf::Clock MoveClock;
    sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
    sf::Vector2f getPosition()      { return body.getPosition(); }
    Collider GetCollider()          { return Collider(body); }

private:
   
    Animation animation;
    unsigned int row;
    unsigned int stop;
    float speed;
    bool faceRight;
    sf::RectangleShape body;

   // sf::SoundBuffer soundJump;
   // sf::Sound sJump;   

    int hp;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    float spawnX;
    int ATK;
  
};

