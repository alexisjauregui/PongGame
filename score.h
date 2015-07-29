//
// Created by Alexis Jauregui on 7/26/15.
//

#ifndef PONGGAME_SCORE_H
#define PONGGAME_SCORE_H


#include <SFML/Graphics/Text.hpp>

class score : public  sf::Text{
public:
    score(sf::Font &font, unsigned int size);
    void IncrementScore();
    void Update();
    int value;

private:


};


#endif //PONGGAME_SCORE_H
