//
// Created by Alexis Jauregui on 7/26/15.
//

#ifndef PONGGAME_BALL_H
#define PONGGAME_BALL_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ball_entity.h"
#include "score.h"
#include "paddle.h"


class ball :public ball_entity{
public:
    ball(score* score1, score* score2, paddle* player1, paddle* player2);
    void Update(sf::RenderWindow* window);
    void Reset(sf::RenderWindow* window);
    ~ball();

    score* score1;
    score* score2;
    sf::SoundBuffer* buffer;
    sf::Sound* sound;
private:

    paddle* player1;
    paddle* player2;

//   sf::SoundBuffer* buffer;
//   sf::Sound* sound;

};


#endif //PONGGAME_BALL_H
