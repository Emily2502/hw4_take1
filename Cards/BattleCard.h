//
// Created by 97250 on 6/11/2022.
//

#ifndef HW4_TAKE1_BATTLECARD_H
#define HW4_TAKE1_BATTLECARD_H
#include "Card.h"
#include <iostream>
using std::ostream;

class BattleCard : public Card {

public:
    BattleCard(int force, int damage, int loot) : Card(), m_force(force), m_damage(damage), m_loot(loot) {}
    void printMonsterDetails(ostream &os, int force, int damage, int coins, bool isDragon);
    void applyEncounter(Player& player) const override = 0;

protected:
    int m_force;
    int m_damage;
    int m_loot;


};


#endif //HW4_TAKE1_BATTLECARD_H
