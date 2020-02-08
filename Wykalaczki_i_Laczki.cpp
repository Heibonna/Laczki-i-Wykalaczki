#include "engine.cpp"
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

/*
TODO//
umki, kontrola walki, pety
*/

int main(){
    srand(time(NULL));

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
    //system("cls");
    bot5.Stats();
	*/
//////
    int opt;
    Character* player = Create_character();
    //dev:
    //player->money += 10000;
    //player->Level_up();
    //player->curr_hp--;

    //

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
        system("cls");
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
            cout << "Game over!\n";
            return 0;
        default:
            opt = -1;
            break;
        }
        cout << endl;
//        system("pause");
    }
    while(opt != 0);
    return 0;
}
//system("clear")
//system("pause")
