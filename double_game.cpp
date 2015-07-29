//
// Created by Alexis Jauregui on 7/26/15.
//

#include "double_game.h"




void double_game::Initialize(sf::RenderWindow *window2) {
    this->font= new sf::Font();
    this->font->loadFromFile("DroidSans.ttf");

    this->score1_d = new score(*font,50);
    this->score1_d->setOrigin(this->score1_d->getGlobalBounds().width / 2,
                              this->score1_d->getGlobalBounds().height / 2);
    this->score1_d->setPosition(200,20);

    this->score2_d = new score(*font,50);
    this->score2_d->setOrigin(this->score2_d->getGlobalBounds().width / 2,
                              this->score2_d->getGlobalBounds().height / 2);
    this->score2_d->setPosition(600,20);

    this->player1_d = new player(0);
    this->player2_d = new player(1);

    this->player1_d->setPosition(0,window2->getSize().y/2-this->player1_d->getGlobalBounds().height/2);
    this->player2_d->setPosition(window2->getSize().x - this->player2_d->getGlobalBounds().width,
                               window2->getSize().y/2-this->player2_d->getGlobalBounds().height/2);
    this->ball1_d = new ball(score1_d,score2_d,this->player1_d,this->player2_d);
    this->ball1_d->setPosition(window2->getSize().x/2,window2->getSize().y/2);


    this->paused_text = new sf::Text(        "               PAUSED\n "
                                                     "       Press Esc to Quit\n "
                                                     "Press Space to Continue", *font, 64U);
    this->paused_text->setOrigin(this->paused_text->getGlobalBounds().width / 2,
                                 this->paused_text->getGlobalBounds().height / 2);
    this->paused_text->setPosition(window2->getSize().x / 2, window2->getSize().y / 2);

    this->red_text = new sf::Text(        "              RED WINS\n "
                                                     "Press Esc to Main Menu\n ", *font, 40U);
    this->red_text->setColor(sf::Color::Red);
    this->red_text->setOrigin(this->red_text->getGlobalBounds().width / 2,
                                 this->red_text->getGlobalBounds().height / 2);
    this->red_text->setPosition(window2->getSize().x / 2, window2->getSize().y / 4);

    this->blue_text = new sf::Text(         "             BLUE WINS\n "
                                                  "Press Esc to Main Menu\n ", *font, 40U);
    this->blue_text->setOrigin(this->blue_text->getGlobalBounds().width / 2,
                              this->blue_text->getGlobalBounds().height / 2);
    this->blue_text->setPosition(window2->getSize().x / 2, window2->getSize().y / 4);
    this->blue_text->setColor(sf::Color::Blue);

    this->paused = false;
    this->enterKey = false;

    this->done = false;
    this->red_wins = false;



}

void double_game::Update(sf::RenderWindow *window) {
    if(this->paused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->enterKey) {
            this->paused = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            coreState.set_state(new main_state());
        }
    }else if(this->done){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                coreState.set_state(new main_state());
            }

    }else {
        this->player1_d->Update();
        this->player2_d->Update();
        this->ball1_d->Update(window);
        this->score1_d->Update();
        this->score2_d->Update();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->enterKey) {
            this->paused = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            coreState.set_state(new main_state());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            coreState.set_state(new main_state);
        }

    }
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

    if(this->score1_d->value == 3){
        red_wins = true;
        done = true;
    }
    if(this->score2_d->value == 3){
        red_wins = false;
        done = true;
    }



}

void double_game::Render(sf::RenderWindow *window) {

    window->draw(*this->player1_d);
    window->draw(*this->player2_d);
    window->draw(*this->ball1_d);
    window->draw(*this->score1_d);
    window->draw(*this->score2_d);
    if (this->paused)
    {
        window->draw(*this->paused_text);
    }

    if(this->done){
        if(this->red_wins){
            window->draw(*this->red_text);
        }else{
            window->draw(*this->blue_text);
        }
    }


}

void double_game::Destroy(sf::RenderWindow *window) {

    delete this->player1_d;
    delete this->player2_d;
    delete this->ball1_d;
    delete this->score1_d;
    delete this->score2_d;
    delete this->font;
    delete this->paused_text;
    delete this->red_text;
    delete this->blue_text;


}
