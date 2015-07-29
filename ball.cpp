//
// Created by Alexis Jauregui on 7/26/15.
//

#include "ball.h"
#include <iostream>

ball::ball(score *score1, score *score2, paddle *player1, paddle *player2) {
    this->setFillColor(sf::Color::Magenta);
    this->score1 = score1;
    this->score2 = score2;
    this->player1 = player1;
    this->player2 = player2;

    this->velocity.x =0.35f;
    this->velocity.y =0.35f;


    this->buffer = new sf::SoundBuffer();
    this->buffer->loadFromFile("boing_x.wav");
    this->sound = new sf::Sound(*this->buffer);


}

void ball::Update(sf::RenderWindow *window) {
    if (this->getGlobalBounds().intersects(this->player1->getGlobalBounds()))
    {
        this->velocity.x *= -1;
        if (this->velocity.y > 0)
        {
            if (this->player1->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
            else if (this->player1->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
        }
        else if (this->velocity.y < 0)
        {
            if (this->player1->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
            else if (this->player1->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
        }
        this->sound->play();
    }
    if (this->getGlobalBounds().intersects(this->player2->getGlobalBounds()))
    {
        this->velocity.x *= -1;
        if (this->velocity.y > 0)
        {
            if (this->player2->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
            else if (this->player2->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
        }
        else if (this->velocity.y < 0)
        {
            if (this->player2->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
            else if (this->player2->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
        }
        this->sound->play();
    }

    if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
        this->sound->play();

    }

    if (this->getPosition().x < 0)
    {

        this->score2->IncrementScore();
        this->Reset(window);
    }
    if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
    {

        this->score1->IncrementScore();
        this->Reset(window);
    }
//Pefect Ball Speed
    if(this->velocity.x > 3.0f  ){
        this->velocity.x= 3.0f;

    }
    if(this->velocity.x < -3.0f  ){
        this->velocity.x= -3.0f;

    }
    if(this->velocity.x < .70f && this->velocity.x>0){
        this->velocity.x = .70f;
    }
    if(this->velocity.x > -.70f && this->velocity.x<0){
        this->velocity.x = -.70f;
    }
    if(this->velocity.y> 1.5f){
        this->velocity.y= 1.5f;
    }
    if(this->velocity.y< -1.5f){
        this->velocity.y= -1.5f;
    }
////////////////////////////////
    ball_entity::Update();

}

void ball::Reset(sf::RenderWindow *window) {
    this->velocity.x = ((rand() % 2) == 0) ? .35f : -.35f;
    this->velocity.y = ((rand() % 2) == 0) ? .35f : -.35f;
    this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
    this->player1->setPosition(0, window->getSize().y / 2 - this->player1->getGlobalBounds().height / 2);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width,
                               window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2);
}


ball::~ball() {
    delete this->sound;
    delete this->buffer;
}
