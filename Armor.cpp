//
// Created by Mateusz Murawski on 06.03.2020.
//

#include <cmath>
#include "Armor.h"

Armor::Armor(int class_number) {
    std::string WEAPONS[6] = { "Fist", "Axe", "Long Sword", "Dagger", "Sword&Shield", "Sword" };
    std::string ARMORS[6] = { "Rags", "Scales", "Cuirasses", "Jacket", "Plate", "Robs" };
    std::string MODS[5] = { "Weak ", "Tolerable " ,"Common ", "Elite ", "Legendary "};

    this->class_number = class_number;
    name = MODS[0] + ARMORS[0];
}

void Armor::UpGrade(int tr) {
    std::string WEAPONS[6] = { "Fist", "Axe", "Long Sword", "Dagger", "Sword&Shield", "Sword" };
    std::string ARMORS[6] = { "Rags", "Scales", "Cuirasses", "Jacket", "Plate", "Robs" };
    std::string MODS[5] = { "Weak ", "Tolerable " ,"Common ", "Elite ", "Legendary "};

    tier = tr;

    if (tr > 4) {
        /*cout << "Max tier. Armor value +10";*/
        name = MODS[4] + ARMORS[class_number];

        if (class_number == 1)
            defence = 10 * pow(2, 4) + 10 * (tr - 4);
        else if (class_number == 2)
            defence = 15 * pow(2, 4) + 10 * (tr - 4);
        else if (class_number == 3)
            defence = 5 * pow(2, 4) + 10 * (tr - 4);
        else if (class_number == 4)
            defence = 15 * pow(2, 4) + 10 * (tr - 4);
    }
    else if (tr == 1) {
        name = MODS[tr - 1] + ARMORS[class_number];

        switch (this->class_number) {
            case 1:
                defence = 10;
            case 2:
                defence = 15;
            case 3:
                defence = 5;
            case 4:
                defence = 15;
        }
    }
    else {
        name = MODS[tr] + ARMORS[class_number];

        if (class_number == 1)
            defence = 10 * pow(2, tr);
        else if (class_number == 2)
            defence = 15 * pow(2, tr);
        else if (class_number == 3)
            defence = 5 * pow(2, tr);
        else if (class_number == 4)
            defence = 20 * pow(2, tr);
    }
}

void Armor::UpGrade() {
    this->UpGrade(tier + 1);
}

void Armor::Examine() {
    cout << name << "\t\ttier: " << tier << " (+" << defence << ")" << endl;
}