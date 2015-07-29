//
// Created by Alexis Jauregui on 7/26/15.
//

#include "player.h"


player::player(int playerNumber)
{
    this->playerNumber = playerNumber;

    switch (this->playerNumber)
    {
        case 1:
            this->setFillColor(sf::Color::Blue);
            break;
        default:
            this->setFillColor(sf::Color::Red);
            break;
    }
}
void player::Update()
{
    switch (this->playerNumber)
    {
        case 0:
            this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
            break;
        default:
            this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
            break;
    }
    entity::Update();

    if (this->getPosition().y < 0)
    {
        this->move(0, 1.0f);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 600)
    {
        this->move(0, -1.0f);
    }
}
