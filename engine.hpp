#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
#include <string.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <conio.h>

using namespace std;

/*
tamplate<char type> class Item{
string name;
int dmg = -1, def = -1,
ehh idk
}
*/
string WEAPONS[6] = { "Fist", "Axe", "Long Sword", "Dagger", "Sword&Shield", "Sword" };
string ARMORS[6] = { "Rags", "Scales", "Cuirasses", "Jacket", "Plate", "Robs" };
string MODS[5] = { "Weak ", "Tolerable " ,"Common ", "Elite ", "Legendary "};

class Item {
public:
	int tier = 0;
	int class_number = 0;
	string name;

	virtual void UpGrade() = 0;
	virtual void UpGrade(int) = 0;
	virtual void Examine() = 0;
};

class Weapon :public Item {
	int damage = 1;
public:
	Weapon(int);
	void UpGrade();
	void UpGrade(int);
	void Examine();
friend class Character;
};

class Armor :public Item {
	int defence = 1;
public:
	Armor(int);
	void UpGrade();
	void UpGrade(int);
	void Examine();
friend class Character;
};

class Character {
protected:
	string name;
	int lvl;
	int strength, durability, dexterity, hp, stamina, charisma;
	int exp = 0;

	int class_value = 0;

	Weapon* weapon;
	Armor* armor;

	//Warrior 1, Paladin 2, Assasin 3, Shielder 4, Pet_Master 5
	//critics,  healer,     2 attacks,  defensive,  petting

public:
	Character();
	~Character();
	Character(int, string);
	Character(string);
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

class City {
public:
	void Arena(Character*);
	void Temple(Character*);
	void Training_ground(Character*);
	void Smithy(Character*);
};

/*
class warrior (critical)           |axe
class paladin (healer)             |sword
class assassin (2 attacks)         |knifes
class tank (def)                   |shield
class arr (pet master)             |sword

template<char type>
class Pet{
private:
string name;
string species;
int level;
public:
Pet(string, string, int);
void pet_skill();
};
*/
Character* PLAYER = new Character;
City Capital;

