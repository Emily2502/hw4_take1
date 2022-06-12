//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_DRAGON_H
#define HW4_TAKE1_DRAGON_H
#include "BattleCard.h"

class Dragon : public BattleCard {

public:
    void applyEncounter(Player& player) const override;
    Dragon() : BattleCard( 25, -1, 1000) {}
};


#endif //HW4_TAKE1_DRAGON_H
