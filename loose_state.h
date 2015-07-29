//
// Created by Alexis Jauregui on 7/28/15.
//

#ifndef PONGGAME_LOOSE_STATE_H
#define PONGGAME_LOOSE_STATE_H

#include <SFML/Graphics.hpp>

#include "game_state.h"
#include "main_state.h"

class loose_state : public tiny_state
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




#endif //PONGGAME_LOOSE_STATE_H
