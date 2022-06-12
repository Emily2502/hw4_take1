//
// Created by 97250 on 6/11/2022.
//

#include "BattleCard.h"
using std::endl;

void BattleCard::printMonsterDetails(ostream &os, int force, int damage, int coins, bool isDragon)

{
    os << "Force: " << force << endl;
    if (isDragon)
        os << "Damage upon loss: " << "Infinite" << endl;
    else
        os << "Damage upon loss: " << damage << endl;
    os << "Coins: " << coins << endl;

}
