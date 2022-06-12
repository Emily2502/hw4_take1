//
// Created by 97250 on 6/10/2022.
//

#include "Vampire.h"

void Vampire::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else
    {
        player.damage(m_damage);
        player.weaken(m_forceToLose);
    }
}
