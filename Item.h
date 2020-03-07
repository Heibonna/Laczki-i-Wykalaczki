//
// Created by heibonna on 06.03.2020.
//

#ifndef LIN_ITEM_H
#define LIN_ITEM_H

#include <iostream>
using namespace std;

class Item {
public:
    int tier = 0;
    int class_number = 0;
    string name;

    virtual void UpGrade() = 0;
    virtual void UpGrade(int) = 0;
    virtual void Examine() = 0;
};

#endif //LIN_ITEM_H
