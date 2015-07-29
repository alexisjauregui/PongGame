//
// Created by Alexis Jauregui on 7/21/15.
//

#ifndef PONGGAME_SINGLE_GAME_H
#define PONGGAME_SINGLE_GAME_H

#include "game_state.h"
#include "main_state.h"
#include "entity.h"
#include "player.h"
#include "score.h"
#include "ball.h"
#include "paddleAI.h"
#include "winscreen.h"
#include "loose_state.h"
#include <iostream>




class single_game : public tiny_state
{
public:

    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
    ~single_game();


private:


    paddleAI* player1;
    player* player2;
    score* score1;
    score* score2;
    ball* ball1;



    sf::Text* paused_text;
    sf::Font* font;

    bool paused,enterKey;

};




#endif //PONGGAME_SINGLE_GAME_H
