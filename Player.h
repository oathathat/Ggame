#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime, int hit);

    void Update(float deltatime);
    void Draw(sf::RenderWindow& window);
    void onCollision(sf::Vector2f direction);
    void SetPosition(float x, float y);
    bool getDirection();
    int GetSpeed();

    sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
    sf::Vector2f GetPosition()      { return body.getPosition(); }
    Collider GetCollider()          { return Collider(body); }
    sf::RectangleShape body;
  

private:

    Animation animation;
    unsigned int row;
    unsigned int stop;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    bool speedUp;
};