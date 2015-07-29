//
// Created by Alexis Jauregui on 7/21/15.
//

#ifndef PONGGAME_ENTITY_H
#define PONGGAME_ENTITY_H


#include <SFML/Graphics.hpp>
#include <string>

class entity : public sf::RectangleShape
{
public:
    sf::Vector2f velocity;

    entity()
    {
        //this->RectangleShape();
        this->setSize({20,100});
    }



    virtual void Update()
    {
        this->move(this->velocity);
    }


    ~entity()
    {

    }
private:

};

#endif