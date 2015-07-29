//
// Created by Alexis Jauregui on 7/26/15.
//

#ifndef PONGGAME_PLAYER_H
#define PONGGAME_PLAYER_H


#include "paddle.h"

class player : public paddle{


    public:
        player(int playerNumber);
        void Update();
    private:
        int playerNumber;
};



#endif //PONGGAME_PLAYER_H
