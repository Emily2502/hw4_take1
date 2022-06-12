//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_VAMPIRE_H
#define HW4_TAKE1_VAMPIRE_H
#include "BattleCard.h"

class Vampire : public BattleCard {

public:
    void applyEncounter(Player& player) const override;
    Vampire() : BattleCard( 10, 10, 2), m_forceToLose(1) {}

private:
    int m_forceToLose;

};


#endif //HW4_TAKE1_VAMPIRE_H
