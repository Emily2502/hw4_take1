//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_MERCHANT_H
#define HW4_TAKE1_MERCHANT_H
#include "Card.h"


class Merchant : public Card {

public:
    void applyEncounter(Player& player) const override;
    Merchant() : m_healthPotion(1), m_healthPotionPrice(5), m_forceBoost(1), m_forceBoostPrice(10) {}

private:
    int m_healthPotion;
    int m_healthPotionPrice;
    int m_forceBoost;
    int m_forceBoostPrice;
};


#endif //HW4_TAKE1_MERCHANT_H
