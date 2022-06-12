//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_GOBLIN_H
#define HW4_TAKE1_GOBLIN_H
#include "BattleCard.h"
int const DEFAULT_FORCE_GOBLIN = 6;
int const DEFAULT_DAMAGE_GOBLIN = 10;
int const DEFAULT_LOOT_GOBLIN = 2;


class Goblin : public BattleCard {

public:
    void applyEncounter(Player& player) const override;
    Goblin() : BattleCard( DEFAULT_FORCE_GOBLIN, DEFAULT_DAMAGE_GOBLIN, DEFAULT_LOOT_GOBLIN) {}

};


#endif //HW4_TAKE1_GOBLIN_H
