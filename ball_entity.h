//
// Created by Alexis Jauregui on 7/26/15.
//

#ifndef PONGGAME_BALL_ENTITY_H
#define PONGGAME_BALL_ENTITY_H

#include <SFML/Graphics.hpp>
class ball_entity : public sf::CircleShape
{
public:
    sf::Vector2f velocity;

    ball_entity()
    {

        this->setRadius({15});

    }



    virtual void Update()
    {
        this->move(this->velocity);
    }


    ~ball_entity()
    {

    }
private:

};
#endif //PONGGAME_BALL_ENTITY_H
