//
// Created by 97250 on 6/10/2022.
//

#include "Barfight.h"

void Barfight::applyEncounter(Player &player) const
{
    if (player.getType() != Player::PlayerType::Fighter)
    {
        player.damage(m_hp);
    }
}
