//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_ROGUE_H
#define HW4_TAKE1_ROGUE_H
#include "Player.h"


class Rogue : public Player {

public:
    void addCoins(int coinsToAdd) override;
    PlayerType getType() const override;
};


#endif //HW4_TAKE1_ROGUE_H
