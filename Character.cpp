//
// Created by heibonna on 06.03.2020.
//
#include "Character.h"


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

    this->strength += up = rand() % (lvl);
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

void Character::Develop(int i) {
    this->curr_exp += i;
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
