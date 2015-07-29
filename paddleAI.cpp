//
// Created by Alexis Jauregui on 7/27/15.
//

#include "paddleAI.h"

paddleAI::paddleAI(int playerNumber,float speednum)
{
    win = false;
    loose = false;
    speed = speednum;
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

void paddleAI::SetBall(ball* ballObject)
{
    this->ballObject = ballObject;
}

void paddleAI::Update()
{
    if (this->ballObject != NULL)
    {
        if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->ballObject->getPosition().y)
        {
            this->velocity.y = this->speed;
        }
        if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->ballObject->getPosition().y)
        {
            this->velocity.y = -this->speed;
        }
    }
// Difficulty goes up;
    if(ballObject->score2->value == 1)
    {
        this->speed = .50f;
    }else if(ballObject->score2->value == 2)
    {
        this->speed = .75f;
    }

   if(ballObject->score2->value == 3){
        this->win = true;
    }
   if(ballObject->score1->value ==3){
       this->loose = true;

   }



    entity::Update();

    if (this->getPosition().y < 0)
    {
        this->move(0, this->speed);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 600)
    {
        this->move(0, -this->speed);
    }
}
