//
// Created by 97250 on 6/10/2022.
//

#include "Dragon.h"

void Dragon::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else
    {
        player.damage(player.getHP());
    }
}
