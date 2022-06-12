#include "Player.h"
#include <iostream>
const int INITIAL_LEVEL = 1;
const int INITIAL_COINS = 0;
const int MAX_LEVEL = 10;

Player::Player(const std::string &name, int maxHp, int force)
{
    if (maxHp <= 0)
    {
        maxHp = DEFAULT_MAX_HP;
    }
    if (force <= 0)
    {
        force = DEFAULT_FORCE;
    }

    m_name = name;
    m_hp = maxHp;
    m_level = INITIAL_LEVEL;
    m_force = force;
    m_maxHp = maxHp;
    m_coins = INITIAL_COINS;
}


void Player::printInfo() const
{
    std::cout << "Player Details:" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Level: " << m_level << std::endl;
    std::cout << "Force: " << m_force << std::endl;
    std::cout << "HP: " << m_hp << std::endl;
    std::cout << "Coins: " << m_coins << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(const int forcePointsToUpgrade)
{
    if (forcePointsToUpgrade > 0)
    {
        m_force += forcePointsToUpgrade;
    }
}

void Player::heal(const int hpPointsToUpgrade)
{
    if (hpPointsToUpgrade > 0)
    {
        if (m_hp + hpPointsToUpgrade >= m_maxHp)
        {
            m_hp = m_maxHp;
            return;
        }
        m_hp += hpPointsToUpgrade;
    }
}

void Player::damage(const int hpPointsToDowngrade)
{
    if (hpPointsToDowngrade > 0)
    {
        if (m_hp - hpPointsToDowngrade <= 0)
        {
            m_hp = 0;
            return;
        }
        m_hp -= hpPointsToDowngrade;
    }
}

bool Player::isKnockedOut() const
{
    if (m_hp == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(const int coinsToAdd)
{
    if (coinsToAdd > 0)
    {
        m_coins += coinsToAdd;
    }
}

bool Player::pay(const int coinsToPay)
{
    if (coinsToPay > 0)
    {
        if (coinsToPay > m_coins)
        {
            return false;
        }
        m_coins -= coinsToPay;
    }
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}

