//
// Created by Alexis Jauregui on 7/28/15.
//

#include "loose_state.h"



void loose_state::Initialize(sf::RenderWindow* window){
    this->font= new sf::Font();
    this->font->loadFromFile("DroidSans.ttf");
    this->messege = new sf::Text("You Loose",*this->font,150U);
    this->messege->setOrigin(this->messege->getGlobalBounds().width/2,this->messege->getGlobalBounds().height/2);
    this->messege->setPosition(window->getSize().x/2,window->getSize().y/8);

    this->messege2 = new sf::Text("Press Space to Continue",*this->font,50U);
    this->messege2->setOrigin(this->messege2->getGlobalBounds().width/2,this->messege2->getGlobalBounds().height/2);
    this->messege2->setPosition(window->getSize().x/2,window->getSize().y/2);
};
void loose_state::Update(sf::RenderWindow* window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        coreState.set_state(new main_state());
    }
};
void loose_state::Render(sf::RenderWindow* window){
    window->draw(*this->messege);
    window->draw(*this->messege2);
};
void loose_state::Destroy(sf::RenderWindow* window){
    delete this->font;
    delete this->messege;
    delete this->messege2;
};