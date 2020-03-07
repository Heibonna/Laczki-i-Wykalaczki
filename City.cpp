//
// Created by Mateusz Murawski on 06.03.2020.
//

#include <unistd.h>
#include "City.h"

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
        usleep(2000);
        cout << ".\n";
        usleep(2000);
        cout << ".\n";
        usleep(2000);
        cout << ".\n";
        usleep(2000);

        if(player -> money >= 200){
            cout << "\nAn influential resident of the city sends help.\n";
            cout << "You are saved, but you lost all your money.\n";
            player -> dead = false;
            player -> curr_hp = player -> hp;
            player -> money = 0;
        }
        else{
            cout << "You are dying in battle. You achieved level " << player -> lvl << ".\n";
            cout << endl << setw(25) << "Game over!" << endl << endl;
            ;
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
