//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_FAIRY_H
#define HW4_TAKE1_FAIRY_H
#include "Card.h"


class Fairy : public Card {

public:
    void applyEncounter(Player& player) const override;
    Fairy() : m_hp(10) {}

private:
    int m_hp;
};


#endif //HW4_TAKE1_FAIRY_H
