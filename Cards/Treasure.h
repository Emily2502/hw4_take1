//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_TREASURE_H
#define HW4_TAKE1_TREASURE_H
#include "Card.h"
int const DEFAULT_COINS_TO_ADD = 10;


class Treasure : public Card {

public:
    explicit Treasure(int coins = DEFAULT_COINS_TO_ADD) : m_coins(coins) {}
    void applyEncounter(Player& player) const override;

private:
    void printTreasureMessage() const;
    int m_coins;

};


#endif //HW4_TAKE1_TREASURE_H
