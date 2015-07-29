//
// Created by Alexis Jauregui on 7/27/15.
//

#ifndef PONGGAME_PADDLEAI_H
#define PONGGAME_PADDLEAI_H

#include "paddle.h"
#include "ball.h"

class paddleAI : public paddle{
public:
    paddleAI(int playerNumber,float speednum);
    void SetBall(ball* ballObject);
    void Update();
    bool win;
    bool loose;

private:
    ball* ballObject;
    int playerNumber;
    float speed;
};



#endif //PONGGAME_PADDLEAI_H
