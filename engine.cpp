/* Mateusz Murawski 2020 All rights reserved */

#pragma once
#include "engine.hpp"

Character::Character() {
	this->lvl = 1;
	this->name = "Bot";
	this->strength = 5;
	this->durability = 5;
	this->dexterity = 5;
	this->hp = 10;
	this->stamina = 5;
	this->charisma = 5;
	this->curr_hp = 10;
	this->exp = 5;

	this->class_value = 1 + rand() % 4;

	this->weapon = new Weapon(class_value);
	this->armor = new Armor(class_value);
}

Character::~Character(){
    delete this->weapon;
    delete this->armor;
}

Character::Character(int cl_va, string whoar) {
	this->lvl = 1;
	this->name = whoar;
	this->strength = 5;
	this->durability = 5;
	this->dexterity = 5;
	this->hp = 10;
	this->stamina = 5;
	this->charisma = 5;
	this->curr_hp = 10;
	this->exp = 5;

	this->class_value = cl_va;

	this->weapon = new Weapon(class_value);
	this->armor = new Armor(class_value);

	/*
	Armor arm();
	this.armor = arm;
	Weapon weap();
	this.weapon = weap;
	*/
}

Character::Character(string whoar) {
	this->lvl = 1;
	this->name = whoar;
	this->strength = 5;
	this->durability = 5;
	this->dexterity = 5;
	this->hp = 10;
	this->stamina = 5;
	this->charisma = 5;
	this->curr_hp = 10;
	this->exp = 5;

	this->class_value = 1 + rand() % 4;

	this->weapon = new Weapon(class_value);
	this->armor = new Armor(class_value);

	/*
	Armor arm();
	this.armor = arm;
	Weapon weap();
	this.weapon = weap;
	*/
}

Character::Character(string whoar, int level) {
	this->lvl = level;
	this->name = whoar;
	this->strength = level*(rand() % (5) + 1) + level;
	this->durability = level*(rand() % (5) + 1) + level;
	this->dexterity = level*(rand() % (5) + 1) + level;
	this->hp = level*(rand() % (5) + 1) + level;
	this->stamina = level*(rand() % (5) + 1) + level;
	this->charisma = level*(rand() % (5) + 1) + level;
	this->curr_hp = this->hp;
	this->exp = 5 * level;

	this->class_value = 1 + rand() % 4;

	this->weapon = new Weapon(class_value);
	this->armor = new Armor(class_value);

	this->armor->UpGrade(floor(level / 5));
	this->weapon->UpGrade(floor(level / 5));
}

void Character::Stats() {
	cout << endl << "My name is: " << this->name;
	if (class_value == 1)
		cout << " the Warrior!" << endl;
	else if (class_value == 2)
		cout << " the Paladin!" << endl;
	else if (class_value == 3)
		cout << " the Assassin!" << endl;
	else if (class_value == 4)
		cout << " the Shielder!" << endl;
	cout << "|lvl|" << lvl << endl
		<< "|str|" << strength << "\t" << "|dur|" << durability << endl
		<< "|dex|" << dexterity << "\t" << "|hp |" << curr_hp << "/" << hp << endl
		<< "|sta|" << stamina << "\t" << "|cha|" << charisma << endl
		<< "|exp|" << curr_exp << "/" << exp << endl
		<< "Coins: " << money << endl
		<< "Abilities: " << points << endl
		<< "Items:" << endl;
	weapon->Examine();
	armor->Examine();
}

void Character::Glance() {
	cout << endl << this->name;
	if (class_value == 1)
		cout << " the Warrior!" << endl;
	else if (class_value == 2)
		cout << " the Paladin!" << endl;
	else if (class_value == 3)
		cout << " the Assassin!" << endl;
	else if (class_value == 4)
		cout << " the Shielder!" << endl;
	cout << "|lvl|" << lvl << endl
		<< "|str|" << strength << "\t" << "|dur|" << durability << endl
		<< "|dex|" << dexterity << "\t" << "|hp |" << hp << endl
		<< "|sta|" << stamina << "\t" << "|cha|" << charisma << endl
		<< "Items:" << endl;
	weapon->Examine();
	armor->Examine();
}

void Character::Show_hp() {
	cout << curr_hp << "/" << hp;
}

void Character::Level_up() {
	int up, perks[6];

	cout << endl << setw(21) << "~~Level up!~~~"
		<< endl << "Your level is now " << ++(this->lvl) << endl;

	this->exp = this->lvl * 5;

	this->strength += (up = rand() % (lvl));
	perks[0] = up;

	this->durability += (up = rand() % (lvl));
	perks[1] = up;

	this->dexterity += (up = rand() % (lvl));
	perks[2] = up;

	this->hp += (up = rand() % (lvl));
	perks[3] = up;

	this->stamina += (up = rand() % (lvl));
	perks[4] = up;

	this->charisma += (up = up % (lvl));
	perks[5] = up;

	this->curr_hp = this->hp;

	printf("|str|+%2d|%2d\t|dur|+%2d|%2d\n|dex|+%2d|%2d\t|hp |+%2d|%2d\n|sta|+%2d|%2d\t|cha|+%2d|%2d\n",
		perks[0], this->strength, perks[1], this->durability, perks[2], this->dexterity,
		perks[3], this->hp, perks[4], this->stamina, perks[5], this->charisma);
	cout << "The number of your ability points: " << (points = points + 10) << endl;
}

void Character::Harmed(float dmg) {
	this->curr_hp -= dmg;

	if (this->curr_hp <= 0) {
		this->curr_hp = 0;
		this->dead = true;
	}
};

void Character::Develop(int exp) {
	this->curr_exp += exp;
	if (this->curr_exp >= this->exp) {
		this->curr_exp -= this->exp;
		this->Level_up();
	}
};

void Character::Train(string what) {
	if ((what == "str")) {
		this->strength++;
		cout << "strength improved! ";
	}
	else if ((what == "dur")) {
		this->durability++;
		this->hp += 2;
		cout << "Durability improved! ";
	}
	else if ((what == "dex")) {
		this->dexterity++;
		cout << "Dexterity improved! ";
	}
	else if ((what == "sta")) {
		this->stamina++;
		cout << "Stamina improved! ";
	}
	else if ((what == "cha")) {
		this->charisma++;
		cout << "Charisma improved! ";
	}
	else {
		cout << "Training failed! ";
	}
}

void Character::Attack(Character* e){

    cout << "You are challenging " << e->name << "!\n\n";

    int st_u = this -> stamina, exp = 0, st_e = e->stamina;
    float hit;

    //warrior && shielder
    if(this -> class_value == 1)
        this -> strength += 2 * this->lvl;
    else if(this -> class_value == 4)
        this -> durability += 2 * this->lvl;
    if(e -> class_value == 1)
        e -> strength += 2 * e->lvl;
    else if(e -> class_value == 4)
        e -> durability += 2 * e->lvl;


    while(true){
        exp++;
        if(rand()%(20*this->lvl) > e->dexterity){
            hit = (rand()%5 + 1) * 0.1 * this->strength * this->weapon->damage
                    - e->armor->defence * 0.05 * e->durability /*-(armor * e->durability przelicznik maly bo dur = hp)*/;
            if(hit < 0)
                hit = 1;
            printf("You deal %.1f damage\n", hit);
            e->Harmed(hit);
        }
        else{
            cout << "You missed!" << endl;
        }

        if(this->dead){
            printf("You lost! Enemy's hp: %f\n", e->curr_hp);

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

            return;
        }
        else if(e->dead){
            exp = exp + e -> lvl;
            printf("\n~~You won!~~\nYour hp: %.1f\nExp gained: %d\nPrize: 100 coins\n", this -> curr_hp, exp);
            this -> Develop(exp);
            this -> money = this -> money +100;

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

            return;
        }

        //assassin
        if(this -> class_value == 3 && (((--st_u)--) > 0)){
            cout << "You have second chance!\n";

            if(rand()%(20*this->lvl) > e->dexterity){
                hit = (rand()%5 + 1)/100.0 * this->strength * this->weapon->damage
                        - e->armor->defence * 0.005 * e->durability /*-(armor * e->durability przelicznik maly bo dur = hp)*/;
                if(hit < 0)
                    hit = 1;
                printf("You deal %.1f damage\n", hit);
                e->Harmed(hit);
            }
            else{
                cout << "You missed!" << endl;
            }

            if(this->dead){
                printf("You lost! Enemy's hp: %f\n", e->curr_hp);

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

                return;
            }
            else if(e->dead){
                exp = exp + e -> lvl;
                printf("\n~~You won!~~\nYour hp: %.1f\nExp gained: %d\nPrize: 100 coins\n", this -> curr_hp, exp);
                this -> Develop(exp);
                this -> money = this -> money +100;

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

                return;
            }
        }

        if(rand()%(20*e->lvl) > this->dexterity){
            hit = (rand()%5 + 1)/100.0 * e->strength * e->weapon->damage
                    - this->armor->defence * 0.005 * this->durability /*-(armor * e->durability przelicznik maly bo dur = hp)*/;
            if(hit < 0)
                hit = 1;
             printf("Enemy deals %.1f damage\n", hit);
            this->Harmed(hit);
        }
        else{
            cout << "Enemy missed!" << endl;
        }

        if(this->dead){
            printf("You lost! Enemy's hp: %.1f\n", e->curr_hp);

            if(this -> class_value == 1)
                this -> strength -= 2 * this->lvl;
            else if(this -> class_value == 4)
                this -> durability -= 2 * this->lvl;
            if(e -> class_value == 1)
                e -> strength -= 2 * e->lvl;
            else if(e -> class_value == 4)
                e -> durability -= 2 * e->lvl;

            return;
        }
        else if(e->dead){
            exp = exp + e -> lvl;
            printf("\n~~You won!~~\nYour hp: %.1f\nExp gained: %d\nPrize: 100 coins\n", this -> curr_hp, exp);
            this -> Develop(exp);
            this -> money = this -> money +100;

            if(this -> class_value == 1)
                this -> strength -= 2 * this->lvl;
            else if(this -> class_value == 4)
                this -> durability -= 2 * this->lvl;
            if(e -> class_value == 1)
                e -> strength -= 2 * e->lvl;
            else if(e -> class_value == 4)
                e -> durability -= 2 * e->lvl;

            return;
        }

        //Assassin
        if(e -> class_value == 3 && (((--st_e)--) > 0)){
            cout << "You were too slow!\n";
            if(rand()%(20*e->lvl) > this->dexterity){
                hit = (rand()%5 + 1)/100.0 * e->strength * e->weapon->damage
                        - this->armor->defence * 0.005 * this->durability /*-(armor * e->durability przelicznik maly bo dur = hp)*/;
                if(hit < 0)
                    hit = 1;
                 printf("Enemy deals %.1f damage\n", hit);
                this->Harmed(hit);
            }
            else{
                cout << "Enemy missed!" << endl;
            }

            if(this->dead){
                printf("You lost! Enemy's hp: %.1f\n", e->curr_hp);

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

                return;
            }
            else if(e->dead){
                exp = exp + e -> lvl;
                printf("\n~~You won!~~\nYour hp: %.1f\nExp gained: %d\nPrize: 100 coins\n", this -> curr_hp, exp);
                this -> Develop(exp);
                this -> money = this -> money +100;

                if(this -> class_value == 1)
                    this -> strength -= 2 * this->lvl;
                else if(this -> class_value == 4)
                    this -> durability -= 2 * this->lvl;
                if(e -> class_value == 1)
                    e -> strength -= 2 * e->lvl;
                else if(e -> class_value == 4)
                    e -> durability -= 2 * e->lvl;

                return;
            }
        }

        //paladin
        if(this -> class_value == 2){
            this -> curr_hp += 0.1 * this->hp;
            cout << "\nYou cured " << 0.1 * this->hp << " hp.\n";
            if(this->curr_hp > this->hp)
                this->curr_hp = this->hp;
        }
        if(e -> class_value == 2){
            e -> curr_hp += 0.1 * e->hp;
            cout << "Your enemy cured " << 0.1 * e->hp << " hp.\n";
            if(e->curr_hp > e->hp)
                e->curr_hp = e->hp;
        }
    }
}

void Character::Cure() {
	this->curr_hp = float(this->hp);

	cout << "You're fully cured!\n";
}

Weapon::Weapon(int class_number) {
	this->class_number = class_number;
	this->name = MODS[0] + WEAPONS[0];
}

void Weapon::UpGrade(int tr) {
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

Armor::Armor(int class_number) {
	this->class_number = class_number;
	name = MODS[0] + ARMORS[0];
}

void Armor::UpGrade(int tr) {
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

void City::Arena(Character* player) {
    int opt;
	cout << "\nYou are on the Arena\n\nYou can see 3 fighters:\n";

	Character novice("Newbie Bob", player->lvl == 1 ? 1 : player->lvl - 1);
        novice.Glance();
    Character regular("Fair Fran", player->lvl+1);
    	regular.Glance();
    Character master("Experienced Ben", player->lvl +5);
        master.Glance();

    do{
        cout << "\nChoose your enemy! ";
        cout << "\n"
            << "1 >> Bob\n"
            << "2 >> Fran\n"
            << "3 >> Ben\n"
            << "0 >> Exit\n";
        cin >> opt;
    }
    while(opt < 0 || opt > 3);

    system("cls");

    if(opt == 0)
        return;
    else if(opt == 1)
    	player->Attack(&novice);
    else if(opt == 2)
        player->Attack(&regular);
    else if(opt == 3)
        player->Attack(&master);

	if(player->dead == true){
        cout << "\nYou are lying in blood pool...\n";
        Sleep(2000);
        cout << ".\n";
        Sleep(2000);
        cout << ".\n";
        Sleep(2000);
        cout << ".\n";
        Sleep(2000);

        if(player -> money >= 200){
            cout << "\nAn influential resident of the city sends help.\n";
            cout << "You are saved, but you lost all your money.\n";
            player -> dead = false;
            player -> curr_hp = player -> hp;
            player -> money = 0;
        }
        else{
            cout << "You are dying in battle. You achieved level " << player -> lvl << ".\n\nGame over.\n";
            exit(0);
        }
	}
}

void City::Temple(Character* player) {
	int opt;

	cout << "\nYou are in the Temple\n\n";

	do {
		cout << "Priest: 'Good morning sir! I see that you have ";
		player->Show_hp();
		cout << " and purse full of gold!\n";
		cout << "I can heal you for 50 coins.'\n"
			<< "1 >> Cure\n"
			<< "0 >> Exit\n";
		cin >> opt;

		if (opt == 1 && player->money >= 50) {
			player->Cure();
            player->dead = false;
			player->money -= 50;
			break;
		}
		else if (opt == 1) {
			cout << "Priest: 'You don't have enough money. Go away!'\n";
			break;
		}
	} while (opt);
}

void City::Training_ground(Character* player) {

	int opt = -1;

	cout << "\nYou are on Training Field\n";

	cout << endl << "Trainer: 'Hi loser!'" << endl;
	cout << "\nYour ability points can be used to extend skills.\n"
		<< "1 >> Train strength\n"
		<< "2 >> Train durability\n"
		<< "3 >> Train dexterity\n"
		<< "4 >> Train stamina\n"
		<< "5 >> Train charisma\n"
		<< "0 >> Exit\n";

	while (opt != 0 && (player->points) > 0) {
		cin >> opt;
		switch (opt) {
		case 1:
			player->Train("str");
			player->points--;
			break;
		case 2:
			player->Train("dur");
			player->points--;
			break;
		case 3:
			player->Train("dex");
			player->points--;
			break;
		case 4:
			player->Train("sta");
			player->points--;
			break;
		case 5:
			player->Train("cha");
			player->points--;
			break;
		case 0:
			break;

		}
		cout << endl << "Remaining points: " << player->points << endl;
	}
	cout << "\nTrainer: 'You cannot learn more today!'\n";
}

void City::Smithy(Character* player) {
	int wep_price = 100, arm_price = 100, tr_wep = player->weapon->tier, tr_arm = player->armor->tier, opt;

	if (tr_wep != 0) {
		wep_price = 250 + (tr_wep - 1) * 750;
	}
	if (tr_arm != 0) {
		arm_price = 250 + (tr_arm - 1) * 750;
	}

	cout << "\nYou visit the Smithy\n"
		<< "\nSmith: 'Hello there!"
		<< "\n\tI can upgrade your equipment:";
	cout << "\n\tYour " << player->weapon->name << " for " << wep_price << " or "
		<< "your " << player->armor->name << " for " << arm_price << "'\n\n";

	cout << "1 >> Upgrade weapon\n"
		<< "2 >> Upgrade armor\n"
		<< "0 >> Exit\n";

	do {
		cin >> opt;
		switch (opt) {
		case 1:
			if (player->money >= wep_price) {
				player->weapon->UpGrade();
				player->money -= wep_price;
				cout << "Smith: 'Done! Your new weapon is: "
					<< player->weapon->name << endl;
				opt = 0;
			}
			else {
				cout << "Smith: 'You don't have enough money. Something else?' ";
			}
			break;
		case 2:
			if (player->money >= arm_price) {
				player->armor->UpGrade();
				player->money -= arm_price;
				cout << "Smith: 'Done! Your new armor is: "
					<< player->armor->name << endl;
				opt = 0;
			}
			else {
				cout << "\nSmith: 'You don't have enough money. Something else?' ";
			}
			break;
		case 0:
			break;
		default:
			cout << "Choose proper option. ";
		}
	} while (opt != 0);

	cout << "\nSmith: 'Come later!'\n";
}

//FUNKCJE:

Character* Create_character() {
	string Name;
	string klass;
    Character* player = PLAYER;

	cout << "\nOh hi! What's your name? ";
	cin >> Name;
	cout << "'Nice to meet you!'\n";
	cout << "'What's your specialization?' [available: Warrior, Paladin, Assassin, Shielder] ";// Arr (Pet Master)

	do {
		cin >> klass;

		if ((klass == "Warrior" || klass == "W" || klass == "w")) {
			player -> class_value = 1;
			player -> name = Name;
			break;
		}
		else if ((klass == "Paladin" || klass == "P" || klass == "p")) {
			player -> class_value = 2;
			player -> name = Name;
			break;
		}
		else if ((klass == "Assassin" || klass == "A" || klass == "a" )) {
			player -> class_value = 3;
			player -> name = Name;
			break;
		}
		else if ((klass == "Shielder" || klass == "S" || klass == "s")) {
			player -> class_value = 4;
			player -> name = Name;
			break;
		}
		else if ((klass == "Arr")) {
			cout << "Try again! ";
			/*PLAYER.class_value = 5;
			break;*/
		}
		else {
			cout << "Try again! ";
		}
	} while (1);

	player->money = 100;

	return player;
}
/*
template <char t> Pet<t>::Pet(string nm, string spcs, int lvl){
this -> name = nm;
this -> species = spcs;
this -> level = lvl;
}

template <char t> void Pet<t>::pet_skill(t){
switch(t){
case 'o':
return;
case 'd':
return;
case 'h':
return;
}
}
*/
