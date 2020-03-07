#ifdef WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
#endif

#include <iostream>
#include "Character.h"
#include "City.h"

using namespace std;

Character* PLAYER = new Character;
City Capital;


Character* Create_character() {
    string Name;
    string klass;
    Character* player = PLAYER;

    cout << "\n'Oh hi! What's your name?' ";
    cin >> Name;
    cout << "'Nice to meet you!'\n";
    cout << "'What's your specialization?' \n[available: Warrior, Paladin, Assassin, Shielder]\n";// Arr (Pet Master)

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


void clr(void) {
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Sleep(unsigned int seconds){
    #ifdef WIN32
        Sleep(1000 * seconds);
    #else
        sleep(seconds);
    #endif
}

int main(){
    srand(time(nullptr));

    Character bot;
    /*
    bot.Stats();
    bot.Level_up();
    bot.Level_up();
    bot.Level_up();
    bot.Level_up();
    bot.Level_up();
    bot.Stats();


    Character bot2("bot2", 10); Character bot3("bot3", 15); Character bot4("bot4", 20); Character bot5("bot5", 25);
    Character bot6("bot2", 30); Character bot7("bot3", 35); Character bot8("bot4", 40); Character bot9("bot5", 45);
    bot2.Stats();
    bot3.Stats();
    bot4.Stats();
    bot5.Stats();
    bot6.Stats();
    bot7.Stats();
    bot8.Stats();
    bot9.Stats();

    cout << endl;

    bot.Attack(&bot5);
    bot.Stats();
    bot5.Stats();
    //player->money += 10000;
    //player->Level_up();
    //player->curr_hp--;
    */
//////
    clr();
    for(int i = 0; i < 25; i++) cout << "~";
    Sleep(1);
    cout << endl << setw(9) << "Laczki\n";
    Sleep(1);
    cout << setw(12) << "i\n";
    Sleep(1);
    cout << setw(25) << "Wykalaczki\n";
    Sleep(1);
    for(int i = 0; i < 25; i++) cout << "~";
    cout << endl;
    Sleep(3);

    clr();

    int opt;

    Character* player = Create_character();


    do{
        opt = -1;
        cout << "\nYou are in the heart of the Republic's capital.\n"
             << "1 >> Go to the arena\n"
             << "2 >> Visit the city temple\n"
             << "3 >> Go to the training ground\n"
             << "4 >> Visit the smithy\n"
             << "5 >> Look in a puddle\n"
             << "0 >> Leave the city (quit game)\n";

        cin >> opt;

        clr();

        switch(opt){
            case 1:
                Capital.Arena(player);
                break;
            case 2:
                Capital.Temple(player);
                break;
            case 3:
                Capital.Training_ground(player);
                break;
            case 4:
                Capital.Smithy(player);
                break;
            case 5:
                player -> Stats();
                break;
            case 0:
                cout << endl << setw(25) << "Game over!" << endl << endl;
                return 0;
            default:
                opt = -1;
                break;
        }
        cout << endl;
//       system("pause");
    }
    while(opt != 0);
    return 0;
}
