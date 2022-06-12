//
// Created by 97250 on 6/10/2022.
//

#include "Treasure.h"

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_coins);
    printTreasureMessage();
}

void Treasure::printTreasureMessage() const
{
    cout << "You've stumbled into a pile of coins! you've gained 10 gold." << endl;
}
