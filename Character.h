//
// Created by heibonna on 06.03.2020.
//

#ifndef LIN_CHARACTER_H
#define LIN_CHARACTER_H
//
// Created by Mateusz Murawski on 06.03.2020.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Character {
protected:
    string name{};
    int lvl;
    int strength, durability, dexterity, hp, stamina, charisma;
    int exp = 0;

    int class_value = 0;

    Weapon* weapon{};
    Armor* armor{};

    //Warrior 1, Paladin 2, Assasin 3, Shielder 4, Pet_Master 5
    //critics,  healer,     2 attacks,  defensive,  petting

public:
    Character();
    ~Character();
    Character(int, string);
    explicit Character(string);
    Character(string, int);

    bool dead = false;
    int money = 0;
    int points = 0;
    int curr_exp = 0;
    float curr_hp = 0;

    void Stats();
    void Glance();

    void Level_up();
    void Develop(int);
    void Train(string);

    void Attack(Character*);
    void Harmed(float);
    void Cure();

    void Show_hp();

    friend Character* Create_character();
    friend class City;
};


#endif //LIN_CHARACTER_H
