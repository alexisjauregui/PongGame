//
// Created by Alexis Jauregui on 7/28/15.
//
#include "block_mode.h"



void block_mode::Initialize(sf::RenderWindow *window) {


    this->font= new sf::Font();
    this->font->loadFromFile("DroidSans.ttf");

    this->score1 = new score(*font,20);
    this->score1->setOrigin(this->score1->getGlobalBounds().width/2,
                            this->score1->getGlobalBounds().height/2);
    this->score1->setPosition(100,20);

    this->score2 = new score(*font,20);
    this->score2->setOrigin(this->score2->getGlobalBounds().width/2,
                            this->score2->getGlobalBounds().height/2);
    this->score2->setPosition(700,20);

    this->player1 = new paddleAI(0,0.25f);
    this->player2 = new player(1);
    this->block1  = new blocks(.5);

    this->player1->setPosition(0,window->getSize().y/2-this->player1->getGlobalBounds().height/2);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width,
                               window->getSize().y/2-this->player2->getGlobalBounds().height/2);

    this->block1->setPosition(window->getSize().x/4,0);
    this->block1->setSize({15,100});

    this->block2  = new blocks(.5);
    this->block2->setPosition(window->getSize().x/4-50,
                              window->getSize().y-this->block2->getGlobalBounds().height-10);
    this->block2->setSize({15,100});

    this->block3  = new blocks(.5);
    this->block3->setPosition(window->getSize().x/4+50,
                              window->getSize().y/3);
    this->block3->setSize({15,100});

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


}

void block_mode::Update(sf::RenderWindow *window) {

    if(this->paused){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->enterKey)
        {
            this->paused = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            coreState.set_state(new main_state());
        }
    }else {


        this->player1->Update();
        this->player2->Update();
        this->ball1->Update(window);
        this->score1->Update();
        this->score2->Update();
        this->block1->Update();

        Collision(this->ball1,this->block1);
        if(this->score2->value >0){
            this->block2->Update();
            Collision(this->ball1,this->block2);
        }
        if(this->score2->value >1){
            this->block3->Update();
            Collision(this->ball1,this->block3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->enterKey) {
            this->paused = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            coreState.set_state(new main_state());
        }
        if (player1->win) {
            coreState.set_state(new winscreen());

        }
        if (player1->loose) {
            coreState.set_state(new loose_state());
        }


    }
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

}

void block_mode::Render(sf::RenderWindow *window) {

    window->draw(*this->player1);
    window->draw(*this->player2);
    window->draw(*this->ball1);
    window->draw(*this->score1);
    window->draw(*this->score2);
    window->draw(*this->block1);
    if(this->score2->value >0){
        window->draw(*this->block2);
    }

    if(this->score2->value >1){
        window->draw(*this->block3);
    }

    if (this->paused)
    {
        window->draw(*this->paused_text);
    }
}

void block_mode::Destroy(sf::RenderWindow *window) {
    delete this->player1;
    delete this->player2;
    delete this->ball1;
    delete this->score1;
    delete this->score2;
    delete this->font;
    delete this->block1;
    delete this->block2;
    delete this->block3;
    delete this->paused_text;

}

void block_mode::Collision(ball *ballx, blocks *blockx) {

    if(ballx->getGlobalBounds().intersects(blockx->getGlobalBounds())) {

        if (ballx->velocity.x < 0){
            ballx->velocity.x *= -1;
    }
        if (ballx->velocity.y > 0)
        {
            if (blockx->velocity.y > 0)
            {
                ballx->velocity.y += ballx->velocity.y * 1.25f;
            }
            else if (blockx->velocity.y < 0)
            {
                ballx->velocity.y += ballx->velocity.y * -1.25f;
            }
        }
        else if (ballx->velocity.y < 0)
        {
            if (blockx->velocity.y > 0)
            {
                ballx->velocity.y += ballx->velocity.y * -1.25f;
            }
            else if (blockx->velocity.y < 0)
            {
                ballx->velocity.y += ballx->velocity.y * 1.25f;
            }
        }
        ballx->sound->play();
    }
}