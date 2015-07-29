//
// Created by Alexis Jauregui on 7/28/15.
//

#include "blocks.h"

blocks::blocks(float speed) {
    this->setFillColor(sf::Color::White);
    this->speed = speed;
    this->velocity.y = speed;
}
void blocks::Update() {


    entity::Update();

    if (this->getPosition().y < 0)
    {
        this->velocity.y = this->speed;

    }
    if (this->getPosition().y + this->getGlobalBounds().height > 600)
    {
        this->velocity.y = -this->speed;

    }


}
