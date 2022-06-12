//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_FIGHTER_H
#define HW4_TAKE1_FIGHTER_H
#include "Player.h"

class Fighter : public Player {

public:
    int getAttackStrength() const override;
    PlayerType getType() const override;
};


#endif //HW4_TAKE1_FIGHTER_H
