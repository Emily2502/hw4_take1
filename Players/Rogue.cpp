//
// Created by 97250 on 6/10/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int coinsToAdd)
{
    Player::addCoins(2*coinsToAdd);
}

Player::PlayerType Rogue::getType() const
{
    return Player::PlayerType::Rogue;
}