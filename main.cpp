//
//  main.cpp
//
//  Project: UALR - Programming 2 - Spring 22 - Power Play 9
//  Created by: Mark McCorkle on 20220317
//  Based on: Code Provided by Sean Orme
//  IDE: CLion 2021.2.3     - VERIFIED
//  IDE: XCode              - UNVERIFIED
//  IDE: Visual Studio 2022 - UNVERIFIED
//  IDE: Linux via g++      - VERIFIED (g++ -std=c++17 -Wall main.cpp Item.cpp Player.cpp Monster.cpp Object.cpp -o main)
//
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "Object.h"
#include "Player.h"
#include "Monster.h"

//std::vector<Monster> createMonsters(const Player& player);                        // Old
void createMonsters( std::vector<Object*>& gameCharacters );                        // New

//void displayBattle(const Player& player, const std::vector<Monster>& monsters);   // Old
void displayBattle( const std::vector<Object*>& gameCharacters );                   // New

//void bringOutYourDead(std::vector<Monster>& monsters);                            // Old
void bringOutYourDead( std::vector<Object*>& gameCharacters );                      // New


int main()
{
    // Old Way:
    //Player player;
    //std::vector<Monster> monsters;

    // New Way:
    // Create the vector of Object pointers that will hold all the games characters(players and monsters):
    std::vector<Object*> gameCharacters;
    // Add a new Player class object as the first element of the vector:
    gameCharacters.push_back( new Player{} );

    while (!gameCharacters[0]->isDead())
    {
        // Old Way:
        // player.levelUp();

        // Old:
        // monsters = createMonsters(player);
        // New:
        createMonsters(gameCharacters);

        std::cout << gameCharacters.size() - 1 << " monster(s) approaches!!" << std::endl;
        system("pause");
        system("cls");

        while (!gameCharacters[0]->isDead() && (gameCharacters.size() - 1) > 0)
        {
            bringOutYourDead(gameCharacters);

            displayBattle( gameCharacters );

            gameCharacters[0]->update( gameCharacters );

            std::cout << std::endl;
            std::for_each(gameCharacters.begin() + 1, gameCharacters.end(), [&](Object* monster)->void
            {
                monster->update( gameCharacters );
            });

            system("pause");
            system("cls");
        }
    }

    if (gameCharacters[0]->isDead())
    {
        std::cout << "You Have Died" << std::endl;
    }
    if (gameCharacters[0]->isDead() && gameCharacters.size() - 1 == 0)
    {
        std::cout << "BUT" << std::endl;
    }
    if (gameCharacters.size() - 1 == 0)
    {
        std::cout << "You have killed the monsters!!!" << std::endl;
    }
    system("pause");

}

// Old Way:
//void displayBattle(const Player& player, const std::vector<Monster>& monsters)
//{
//    Object::nameOnly = false; //TODO:: get rid of this and just dot he full cout.
//    std::cout << player << std::endl;
//    std::cout << std::endl << "  Monsters: " << std::endl;
//    {
//        int i{ 1 };
//        std::for_each(monsters.begin(), monsters.end(), [&](const Monster& monster)
//        {
//            std::cout << "   " << i << ". " << monster << std::endl;
//
//            i++;
//        });
//    }
//}

void displayBattle( const std::vector<Object*>& gameCharacters )
{
    Object::nameOnly = false; //TODO:: get rid of this and just dot he full cout.
    std::cout << *gameCharacters[0] << std::endl;
    std::cout << std::endl << "  Monsters: " << std::endl;
    {
        int i{ 1 };
        std::for_each(gameCharacters.begin() + 1, gameCharacters.end(), [&](const Object* monster)->void
        {
            std::cout << "   " << i << ". " << *monster << std::endl;

            i++;
        });
    }
}

// Old Way:
//std::vector<Monster> createMonsters(const Player& player)
//{
//    std::normal_distribution<double> randomNumMonsters((double)player.getLevel(), player.getLevel() / 2.0);
//    std::vector<Monster> monsters(std::max(1, (int)randomNumMonsters(Object::engine)));
//    std::generate(monsters.begin(), monsters.end(), [&]()
//    {
//        return Monster(player);
//    });
//    return monsters;
//}

void createMonsters( std::vector<Object*>& gameCharacters )
{
    // Changed player to the first element of the passed in vector:
    std::normal_distribution<double> randomNumMonsters((double)gameCharacters[0]->getLevel(),
                                                       gameCharacters[0]->getLevel() / 2.0);

    // Insert the number of elements needed (based off of random number of monsters) into the vector:
    gameCharacters.insert( gameCharacters.begin() + 1, std::max(1, (int)randomNumMonsters(Object::engine)), {} );

    // Loop through the vector, starting at the second element(monsters start at the second element):
    std::generate(gameCharacters.begin() + 1, gameCharacters.end(), [&](  )->Monster*
    {
        return new Monster( gameCharacters );
    });
}

// Old Way:
//void bringOutYourDead(std::vector<Monster>& monsters)
//{
//    Object::nameOnly = true;
//    monsters.erase(
//            std::remove_if(monsters.begin(), monsters.end(),
//                           [](Object& monster)
//                           {
//                               if (monster.isDead())
//                               {
//
//                                   std::cout << monster << " has died!!!" << std::endl << std::endl;
//                                   return true;
//                               }
//                               return false;
//                           }),
//            monsters.end());
//
//}

void bringOutYourDead( std::vector<Object*>& gameCharacters )
{
    Object::nameOnly = true;
    gameCharacters.erase(
            std::remove_if(gameCharacters.begin() + 1, gameCharacters.end(), []( Object* monster )->bool
                           {
                               if (monster->isDead())
                               {

                                   std::cout << *monster << " has died!!!" << std::endl << std::endl;
                                   return true;
                               }
                               return false;
                           }),
            gameCharacters.end());

}
