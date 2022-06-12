//
// Created by 97250 on 6/10/2022.
//

#include "Fighter.h"

int Fighter::getAttackStrength() const
{
    return 2 * Player::getAttackStrength() - Player::getLevel();
}

Player::PlayerType Fighter::getType() const
{
    return Player::PlayerType::Fighter;
}
