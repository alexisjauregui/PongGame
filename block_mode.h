//
// Created by Alexis Jauregui on 7/28/15.
//

#ifndef PONGGAME_BLOCK_MODE_H
#define PONGGAME_BLOCK_MODE_H



#include "game_state.h"
#include "main_state.h"
#include "entity.h"
#include "player.h"
#include "score.h"
#include "ball.h"
#include "paddleAI.h"
#include "winscreen.h"
#include "loose_state.h"
#include "blocks.h"
#include <iostream>

class block_mode : public tiny_state
    {
    public:

        void Initialize(sf::RenderWindow* window);
        void Update(sf::RenderWindow* window);
        void Render(sf::RenderWindow* window);
        void Destroy(sf::RenderWindow* window);
        void Collision(ball* ball, blocks* blockx);
        ~block_mode();


    private:


        paddleAI* player1;
        player* player2;
        score* score1;
        score* score2;
        ball* ball1;
        blocks* block1;
        blocks* block2;
        blocks* block3;



        sf::Text* paused_text;
        sf::Font* font;

        bool paused,enterKey;

};




#endif //PONGGAME_BLOCK_MODE_H
