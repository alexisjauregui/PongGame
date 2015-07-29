//
// Created by Alexis Jauregui on 7/27/15.
//

#ifndef PONGGAME_WINSCREEN_H
#define PONGGAME_WINSCREEN_H

#include "game_state.h"
#include "main_state.h"


class winscreen : public tiny_state
{
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);

private:
    sf::Font* font;
    sf::Text* messege;
    sf::Text* messege2;
};




#endif //PONGGAME_WINSCREEN_H
