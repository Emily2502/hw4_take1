//
// Created by 97250 on 6/10/2022.
//

#include "Pitfall.h"

void Pitfall::applyEncounter(Player &player) const
{
    if (player.getType() != Player::PlayerType::Rogue)
    {
        player.damage(m_hp);
    }
}
