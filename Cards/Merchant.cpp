//
// Created by 97250 on 6/10/2022.
//

#include "Merchant.h"

void Merchant::applyEncounter(Player &player) const
{
    //printMerchantInitialMessageForInteractiveEncounter();
    int input; // = getInput();
    if (input == 1)
    {
        if (!player.pay(m_healthPotionPrice))
        {
            //printMerchantInsufficientCoins();
            return;
        }
        player.heal(m_healthPotion);
    }
    else if (input == 2)
    {
        if (!player.pay(m_forceBoostPrice))
        {
            //printMerchantInsufficientCoins();
            return;
        }
        player.buff(m_forceBoost);
    }
    //printMerchantSummary();
}
