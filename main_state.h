//
// Created by Alexis Jauregui on 7/20/15.
//

#ifndef PONGGAME_TEST_STATE_H
#define PONGGAME_TEST_STATE_H

#include "game_state.h"
#include "single_game.h"
#include "double_game.h"
#include "block_mode.h"
#include "winscreen.h"


class main_state: public tiny_state
{
public:

    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
    ~main_state();

private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* play;
    sf::Text* d_play;
    sf::Text* block;
    sf::Text* quit;

    int selected;
    bool upKey;
    bool downKey;
};


#endif //PONGGAME_TEST_STATE_H
