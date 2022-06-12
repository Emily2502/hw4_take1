//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_WIZARD_H
#define HW4_TAKE1_WIZARD_H
#include "Player.h"

class Wizard : public Player {

public:
    void heal(int hpPointsToUpgrade) override;
    PlayerType getType() const override;
};


#endif //HW4_TAKE1_WIZARD_H
