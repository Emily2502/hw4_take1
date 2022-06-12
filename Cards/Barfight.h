//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_BARFIGHT_H
#define HW4_TAKE1_BARFIGHT_H
#include "Card.h"

class Barfight : public Card {

public:
    void applyEncounter(Player& player) const override;
    Barfight() : m_hp(10) {}

private:
    int m_hp;
};




#endif //HW4_TAKE1_BARFIGHT_H
