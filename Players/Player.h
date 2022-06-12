#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#include <string>
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;



class Player {

public:
    enum class PlayerType {Rogue, Fighter, Wizard};

    /**
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHp - The maximum HP possible for the player.
     * @param force - The force of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(const std::string &name, int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);


    /**
     * Copy c'tor of Player class
     *
     * @param Player& - Reference to player to copy.
     * @return
     *      A new instance of Player.
    */
    Player(const Player&) = default;


    /**
     * D'tor of Player class
     *
     * @return
     *      void
    */
    ~Player() = default;


    /**
     * assignment operator for Player class
    */
    Player& operator=(const Player&) = default;


    /**
     * Prints information of a Player in the following format:
     *
     * Player Details:
     * Name:
     * Level:
     * Force:
     * HP:
     * Coins:
     * ------------------------
     *
     * @return
     *      void
    */
    void printInfo() const;


    /**
     * Increases the level of a player by one
     * if player's level is at maximum value already nothing will be done
     *
     * @return
     *      void
    */
    void levelUp();


    /**
     * Gets the level of a player
     *
     * @return
     *      level of said player
    */
    int getLevel() const;


    /**
     * Gets HP of a player
     *
     * @return
     *      HP of said player
    */
    int getHP() const { return m_hp; }


    /**
     * Increases the force of a player
     *
     * @param forcePointsToUpgrade - Number of points to increase player's force by.
     * @return
     *      void
    */
    void buff(int forcePointsToUpgrade);


    /**
     * Increases HP of a player
     *
     * @param hpPointsToUpgrade - Number of points to increase player's HP by.
     * @return
     *      void
    */
    virtual void heal(int hpPointsToUpgrade);


    /**
     * Decreases HP of a player
     *
     * @param hpPointsToDowngrade - Number of points to decrease player's HP by.
     * @return
     *      void
    */
    void damage(int hpPointsToDowngrade);


    /**
     * Decreases HP of a player
     *
     * @param hpPointsToDowngrade - Number of points to decrease player's HP by.
     * @return
     *      void
    */
    void weaken(int forcePointsToDowngrade) {m_force -= forcePointsToDowngrade;}

    /**
     * Checks if HP of a player is zero
     *
     * @return
     *      true - if HP of said player is zero
     *      false - otherwise
    */
    bool isKnockedOut() const;


    /**
     * Increases number of coins of a player
     *
     * @param coinsToAdd - Number of points to increase player's coins by.
     * @return
     *      void
    */
    virtual void addCoins(int coinsToAdd);


    /**
     * Makes a player pay
     * if said player has enough coins then this function decreases the number of coins
     * they have.
     *
     * @param coinsToPay - Number of points to a player has to pay.
     * @return
     *      true - if said player has enough coins
     *      false - otherwise
    */
    bool pay(int coinsToPay);


    /**
     * Gets attack strength of a player
     * attack strength is define by force + level
     *
     * @return
     *      attack strength of said player
    */
    virtual int getAttackStrength() const;

    virtual PlayerType getType() const = 0;


private:

    std::string m_name;  /** English letters. no spaces */
    int m_hp;  /** [0,maxHp] */
    int m_level;  /** [1,10] */
    int m_force;  /** natural number */
    int m_maxHp;  /** natural number */
    int m_coins;  /** non-negative integer */
};

#endif //HW2_PLAYER_H
