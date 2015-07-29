//
// Created by Alexis Jauregui on 7/20/15.
//
#include <iostream>
#include "main_state.h"


void main_state::Initialize(sf::RenderWindow* window)
{


    this->selected = 0;

    this->font= new sf::Font();
    this->font->loadFromFile("DroidSans.ttf");

    this->title = new sf::Text("Pong",*this->font,256U);
    this->title->setOrigin(this->title->getGlobalBounds().width/2,this->title->getGlobalBounds().height/2);
    this->title->setPosition(window->getSize().x/2,window->getSize().y/8);

    this->play = new sf::Text("1 Player",*this->font, 60U);
    this->play->setOrigin(this->play->getGlobalBounds().width/2,this->play->getGlobalBounds().height/2);
    this->play->setPosition(window->getSize().x/2,window->getSize().y*.50);

    this->d_play = new sf::Text("2 Player",*this->font, 60U);
    this->d_play->setOrigin(this->d_play->getGlobalBounds().width/2,this->play->getGlobalBounds().height/2);
    this->d_play->setPosition(window->getSize().x/2,window->getSize().y*.60);

    this->block = new sf::Text("Blockade Mode",*this->font, 60U);
    this->block->setOrigin(this->block->getGlobalBounds().width/2,this->block->getGlobalBounds().height/2);
    this->block->setPosition(window->getSize().x/2,window->getSize().y*.70);

    this->quit = new sf::Text("Quit",*this->font,60U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width/2,this->quit->getGlobalBounds().height/2);
    this->quit->setPosition(window->getSize().x/2,window->getSize().y*.80);
}

void main_state::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) and !this->upKey){
        this->selected -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) and !this->downKey){
        this->selected += 1;
    }
    if(selected < 0){
        this->selected = 3;
    }
    if(selected > 3){
        this->selected = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        switch (this->selected) {
            case 0:
                coreState.set_state(new single_game());
                break;
            case 1:

                coreState.set_state(new double_game());
                break;
            case 2:
                coreState.set_state(new block_mode());
                break;
            case 3:
                quit_game = true;
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

}
void main_state::Render(sf::RenderWindow* window){
    this->play->setColor(sf::Color::White);
    this->d_play->setColor(sf::Color::White);
    this->block->setColor(sf::Color::White);
    this->quit->setColor(sf::Color::White);

    switch (this->selected) {
        case 0:
            this->play->setColor(sf::Color::Red);
            break;
        case 1:
            this->d_play->setColor(sf::Color::Red);
            break;
        case 2:
            this->block->setColor(sf::Color::Red);
            break;
        case 3:
            this->quit->setColor(sf::Color::Red);
            break;

    }

    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->d_play);
    window->draw(*this->block);
    window->draw(*this->quit);

}
void main_state::Destroy(sf::RenderWindow* window){

    delete this->font;
    delete this->title;
    delete this->play;
    delete this->d_play;
    delete this->block;
    delete this->quit;


}

