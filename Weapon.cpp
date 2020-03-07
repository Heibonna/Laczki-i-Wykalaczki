//
// Created by Mateusz Murawski on 06.03.2020.
//

#include "Weapon.h"
#include "Armor.h"
#include <cmath>

Weapon::Weapon(int class_number) {
    std::string WEAPONS[6] = { "Fist", "Axe", "Long Sword", "Dagger", "Sword&Shield", "Sword" };
    std::string ARMORS[6] = { "Rags", "Scales", "Cuirasses", "Jacket", "Plate", "Robs" };
    std::string MODS[5] = { "Weak ", "Tolerable " ,"Common ", "Elite ", "Legendary "};

    this->class_number = class_number;
    this->name = MODS[0] + WEAPONS[0];
}

void Weapon::UpGrade(int tr) {
    std::string WEAPONS[6] = { "Fist", "Axe", "Long Sword", "Dagger", "Sword&Shield", "Sword" };
    std::string ARMORS[6] = { "Rags", "Scales", "Cuirasses", "Jacket", "Plate", "Robs" };
    std::string MODS[5] = { "Weak ", "Tolerable " ,"Common ", "Elite ", "Legendary "};

    tier = tr;
    if (tr > 4) {
        /*cout << "Max tier. Weapon value +10";*/
        name = MODS[4] + WEAPONS[class_number];

        if (class_number == 1)
            damage = 10 * pow(2, 4) + (tr - 4) * 10;
        else if (class_number == 2)
            damage = 5 * pow(2, 4) + (tr - 4) * 10;
        else if (class_number == 3)
            damage = 10 * pow(2, 4) + (tr - 4) * 10;
        else if (class_number == 4)
            damage = 5 * pow(2, 4) + (tr - 4) * 10;
    }
    else if (tr == 1) {
        name = MODS[tr - 1] + WEAPONS[class_number];

        switch (this->class_number) {
            case 1:
                damage = 10;
            case 2:
                damage = 5;
            case 3:
                damage = 8;
            case 4:
                damage = 5;
        }
    }
    else {
        name = MODS[tr] + WEAPONS[class_number];

        if (class_number == 1)
            damage = 10 * pow(2, tr);
        else if (class_number == 2)
            damage = 5 * pow(2, tr);
        else if (class_number == 3)
            damage = 10 * pow(2, tr);
        else if (class_number == 4)
            damage = 5 * pow(2, tr);
    }


}

void Weapon::UpGrade() {
    this->UpGrade(tier + 1);
}

void Weapon::Examine() {
    cout << name << "\t\ttier: " << tier << " (+" << damage << ")" << endl;
}
