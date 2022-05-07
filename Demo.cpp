/**
 * Demo program for Coup exercise
 *
 * @author: Renana Rimon
 * @since: 2022-02
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

    Game game;
    cout << "game size: " << game._size << endl;

    Duke duke{game, "Reut"};
    Assassin assassin{game, "talya"};
    Ambassador ambassador{game, "tahel"};
    Captain captain{game, "renana"};
    Contessa contessa{game, "boaz"};
    Captain captain2{game, "shir"};

    cout << "******* player's coins: *******" << endl;
    for (Player *p : game._players)
    {
        cout << p->getName() << ": " << p->coins() << " coins" << endl;
    }

    try
    {
        assassin.income();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        duke.block(captain);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << "start game with " << game._size << " players" << endl;
    duke.tax();               //+3
    assassin.foreign_aid();   //+2
    ambassador.income();      //+1
    captain.income();         //+1
    contessa.foreign_aid();   //+2
    captain2.foreign_aid();   //+2
    duke.tax();               // 6
    assassin.foreign_aid();   // 4
    ambassador.foreign_aid(); // 3
    captain.foreign_aid();    // 3
    contessa.foreign_aid();   // 4
    captain2.foreign_aid();   // 4
    duke.block(ambassador);   // not need turn

    cout << "******* player's coins: *******" << endl;
    for (Player *p : game._players)
    {
        cout << p->getName() << ": " << p->coins() << " coins" << endl;
    }
    cout << "***************************" << endl;

    /*coup & block*/
    duke.income();           // 7
    assassin.coup(captain2); //-3
    ambassador.income();     //+1
    contessa.block(assassin);
    captain.income();       //+1
    contessa.income();      //+1
    captain2.foreign_aid(); //+2
    duke.coup(captain2);    // -7 -> capitan2 out of game
    try
    {
        captain.block(duke);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "******* player's coins: *******" << endl;
    /*check coins & players*/
    for (Player *p : game._players)
    {
        cout << p->getName() << ": " << p->coins() << " coins" << endl;
    }
    cout << "***************************" << endl;
    /*increase to 10 coins*/
    assassin.foreign_aid();   //+2
    ambassador.foreign_aid(); //+2
    captain.foreign_aid();    //+2
    contessa.foreign_aid();   //+2
    duke.tax();               //+3
    assassin.foreign_aid();   //+2
    ambassador.foreign_aid(); //+2
    captain.foreign_aid();    //+2
    contessa.foreign_aid();   //+2
    duke.tax();               //+3
    assassin.foreign_aid();   //+2
    ambassador.foreign_aid(); //+2
    captain.foreign_aid();    //+2
    contessa.foreign_aid();   //+2


    /*move with 10 coins*/
    duke.block(contessa);
    duke.income();       //+1
    assassin.income();   //+1
    ambassador.income(); //+1
    try
    {
        captain.income();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    captain.coup(assassin); //-7
    contessa.income(); //+1
    duke.coup(contessa);                       //-7
    ambassador.coup(duke);                     //-7
    try
    {
        assassin.income();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout <<game._size << " players in game:\n";
    for (string p : game.players())
    {
        cout << p << endl;
    }
    cout << "******* player's coins: *******" << endl;
    for (Player *p : game._players)
    {
        cout << p->getName() << ": " << p->coins() << " coins" << endl;
    }
    cout << "***************************" << endl;
    /*2 players*/
    try
    {
        game.winner();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    captain.foreign_aid();     //+2
    ambassador.income();       //+1
    captain.steal(ambassador); // +2, -2
    ambassador.income();       //+1
    captain.steal(ambassador); // +1, -1
    ambassador.income();       //+1

    /*end game*/
    captain.coup(ambassador); // -7

    cout << "the winner is: " << game.winner() << endl;
}