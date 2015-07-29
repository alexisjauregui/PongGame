//
// Created by Alexis Jauregui on 7/28/15.
//

#ifndef PONGGAME_BLOCKS_H
#define PONGGAME_BLOCKS_H

#include <SFML/Graphics.hpp>
#include "score.h"
#include "entity.h"
#include "ball.h"


class blocks : public entity
{
public:
    blocks(float speed);
    void Update();

private:
    float speed;
};


#endif //PONGGAME_BLOCKS_H
