//
// Created by Alexis Jauregui on 7/26/15.
//

#ifndef PONGGAME_DOUBLE_GAME_H
#define PONGGAME_DOUBLE_GAME_H



#include "game_state.h"
#include "main_state.h"
#include "entity.h"
#include "player.h"
#include "score.h"
#include "ball.h"
#include <iostream>



class double_game : public tiny_state
{
public:

    void Initialize(sf::RenderWindow* window2);
    void Update(sf::RenderWindow* window2);
    void Render(sf::RenderWindow* window2);
    void Destroy(sf::RenderWindow* window2);
    ~double_game();

private:


    player* player1_d;
    player* player2_d;
    score* score1_d;
    score* score2_d;
    ball* ball1_d;



    sf::Text* paused_text;
    sf::Text* red_text;
    sf::Text* blue_text;
    sf::Font* font;

    bool paused,enterKey;
    bool done, red_wins;

};


#endif //PONGGAME_DOUBLE_GAME_H
