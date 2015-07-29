//
// Created by Alexis Jauregui on 7/21/15.
//

#include "single_game.h"



void single_game::Initialize(sf::RenderWindow *window) {


    this->font= new sf::Font();
    this->font->loadFromFile("DroidSans.ttf");

    this->score1 = new score(*font,50);
    this->score1->setOrigin(this->score1->getGlobalBounds().width/2,
                           this->score1->getGlobalBounds().height/2);
    this->score1->setPosition(200,20);

    this->score2 = new score(*font,50);
    this->score2->setOrigin(this->score2->getGlobalBounds().width/2,
                            this->score2->getGlobalBounds().height/2);
    this->score2->setPosition(600,20);

    this->player1 = new paddleAI(0,0.25f);
    this->player2 = new player(1);

    this->player1->setPosition(0,window->getSize().y/2-this->player1->getGlobalBounds().height/2);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width,
                               window->getSize().y/2-this->player2->getGlobalBounds().height/2);

    this->ball1 = new ball(score1,score2,this->player1,this->player2);
    this->ball1->setPosition(window->getSize().x/2,window->getSize().y/2);

    this->player1->SetBall(this->ball1);

    this->paused_text = new sf::Text(        "               PAUSED\n "
                                             "       Press Esc to Quit\n "
                                             "Press Space to Continue", *font, 64U);
    this->paused_text->setOrigin(this->paused_text->getGlobalBounds().width / 2,
                                 this->paused_text->getGlobalBounds().height / 2);
    this->paused_text->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    this->paused = false;
    this->enterKey = false;


};

void single_game::Update(sf::RenderWindow *window) {

    if(this->paused){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->enterKey)
        {
            this->paused = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            coreState.set_state(new main_state());
        }
    }else{
        this->player1->Update();
        this->player2->Update();
        this->ball1->Update(window);
        this->score1->Update();
        this->score2->Update();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)&& !this->enterKey)
        {
            this->paused = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
            coreState.set_state(new main_state());
        }
        if(player1->win){
            coreState.set_state(new winscreen());

        }
        if(player1->loose){
            coreState.set_state(new loose_state());
        }

    }
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

}

void single_game::Render(sf::RenderWindow *window) {

    window->draw(*this->player1);
    window->draw(*this->player2);
    window->draw(*this->ball1);
    window->draw(*this->score1);
    window->draw(*this->score2);

    if (this->paused)
    {
        window->draw(*this->paused_text);
    }

};

void single_game::Destroy(sf::RenderWindow *window) {
    delete this->player1;
    delete this->player2;
    delete this->ball1;
    delete this->score1;
    delete this->score2;
    delete this->font;
    delete this->paused_text;

}
