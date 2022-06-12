//
// Created by 97250 on 6/10/2022.
//

#include "Wizard.h"

void Wizard::heal(int hpPointsToUpgrade)
{
    Player::heal(2 * hpPointsToUpgrade);
}

Player::PlayerType Wizard::getType() const
{
    return Player::PlayerType::Wizard;
}
