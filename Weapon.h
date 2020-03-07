//
// Created by Mateusz Murawski on 06.03.2020.
//

#ifndef LIN_WEAPON_H
#define LIN_WEAPON_H

#include <iostream>
#include "Item.h"

class Weapon : public Item {
    int damage = 1;
public:
    Weapon(int);
    void UpGrade();
    void UpGrade(int);
    void Examine();
    friend class Character;
};

#endif //LIN_WEAPON_H
