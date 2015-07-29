//
// Created by Alexis Jauregui on 7/26/15.
//

#include "score.h"
#include <iostream>



score::score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size)
{
    this->value = 0;
}

void score::IncrementScore()
{

    this->value += 1;

}

void score::Update()
{

    this->setString("Score: " + std::to_string(this->value));
}