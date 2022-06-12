//
// Created by 97250 on 6/10/2022.
//

#ifndef HW4_TAKE1_CARD_H
#define HW4_TAKE1_CARD_H
#include "../Players/Player.h"
#include <iostream>
using std::cout;
using std::string;
using std::ostream;
using std::endl;


class Card {

public:

    explicit Card() = default;

    /**
     * C'tor of Card class
     *
     *
     * @return
     *      A new instance of Card.
    */
    explicit Card(string &name) : m_name(name) {}


    /**
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /**
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


private:
    string m_name;
};


#endif //HW4_TAKE1_CARD_H
