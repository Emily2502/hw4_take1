//
// Created by 97250 on 6/10/2022.
//

#include "Fairy.h"

void Fairy::applyEncounter(Player &player) const
{
    if (player.getType() == Player::PlayerType::Wizard)
    {
        player.heal(m_hp);
    }
}
