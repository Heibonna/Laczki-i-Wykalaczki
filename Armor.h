//
// Created by Mateusz Murawski on 06.03.2020.
//

#ifndef LIN_ARMOR_H
#define LIN_ARMOR_H

#include "Item.h"

class Armor : public Item {
    int defence = 1;
public:
    Armor(int);
    void UpGrade();
    void UpGrade(int);
    void Examine();
    friend class Character;
};


#endif //LIN_ARMOR_H
