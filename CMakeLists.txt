cmake_minimum_required(VERSION 3.22)
project(hw4_take1)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw4_take1 main.cpp Players/Player.cpp Players/Player.h Players/Rogue.cpp Players/Rogue.h Players/Wizard.cpp Players/Wizard.h Players/Fighter.cpp Players/Fighter.h Cards/Barfight.cpp Cards/Barfight.h Cards/Card.cpp Cards/Card.h Cards/Dragon.cpp Cards/Dragon.h Cards/Fairy.cpp Cards/Fairy.h Cards/Goblin.cpp Cards/Goblin.h Cards/Merchant.cpp Cards/Merchant.h Cards/Pitfall.cpp Cards/Pitfall.h Cards/Treasure.cpp Cards/Treasure.h Cards/Vampire.cpp Cards/Vampire.h Exception.h Mtmchkin.cpp Mtmchkin.h Cards/BattleCard.cpp Cards/BattleCard.h utilities.cpp utilities.h Queue.h)
