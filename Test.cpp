#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

TEST_CASE("GAME_DEMO"){
    Game game;
    CHECK_EQ(game._size, 0);
    CHECK_THROWS_MESSAGE(game.turn(), "no players in game");
    CHECK_THROWS_MESSAGE(game.winner(), "no players in game");

    Duke duke{game, "Reut"};
	Assassin assassin{game, "talya"};
	Ambassador ambassador{game, "tahel"};
	Captain captain{game, "renana"};
	Contessa contessa{game, "boaz"};
    Captain captain2{game, "shir"};

    CHECK(duke.coins() == 0);
    for (Player* p : game._players)
    {
        CHECK_EQ(p->coins(), 0);
    }

    CHECK_EQ(game._size, 6);

    CHECK_THROWS_MESSAGE(assassin.income(), "not assassign turn");
    CHECK_THROWS_MESSAGE(duke.block(captain), "can block only foreign_aid");

    /*Allow moves*/
    CHECK_NOTHROW(duke.tax()); //+3
    CHECK_NOTHROW(assassin.foreign_aid()); //+2
    CHECK_NOTHROW(ambassador.income()); //+1
    CHECK_NOTHROW(captain.income()); //+1
    CHECK_NOTHROW(contessa.foreign_aid()); //+2
    CHECK_NOTHROW(captain2.foreign_aid()); //+2
    CHECK_NOTHROW(duke.tax()); //6
    CHECK_NOTHROW(assassin.foreign_aid()); //4
    CHECK_NOTHROW(ambassador.foreign_aid()); //3
    CHECK_NOTHROW(captain.foreign_aid()); //3
    CHECK_NOTHROW(contessa.foreign_aid()); //4
    CHECK_NOTHROW(captain2.foreign_aid()); //4
    CHECK_NOTHROW(duke.block(ambassador)); // not need turn

    

    SUBCASE("check coins"){
        CHECK_EQ(ambassador.coins(), 1); //1
        CHECK_EQ(duke.coins(), 6); //6
        CHECK_EQ(captain.coins(), 3); //3
        CHECK_EQ(assassin.coins(), 4); //4
        CHECK_EQ(contessa.coins(), 4); //4
        CHECK_EQ(captain2.coins(), 4); //4
    }

    SUBCASE("not allowed moves"){
        CHECK_THROWS_MESSAGE(duke.block(duke), "can't block itself");
        CHECK_THROWS_MESSAGE(ambassador.block(captain2), "capitan2 didn't steal");
        CHECK_THROWS_MESSAGE(ambassador.block(duke), "ambassador can block only capitan");
        CHECK_THROWS_MESSAGE(contessa.block(assassin), "assassin didn't couped");
        CHECK_THROWS_MESSAGE(contessa.block(ambassador), "contessa can block only assassin");
        CHECK_THROWS_MESSAGE(contessa.income(), "not your turn");
    }

    /*coup & block*/
    CHECK_NOTHROW(duke.income()); // 7
    CHECK_NOTHROW(assassin.coup(captain2)); //-3
    CHECK_NOTHROW(ambassador.income()); //+1
    CHECK_NOTHROW(contessa.block(assassin));
    CHECK_NOTHROW(captain.income()); //+1
    CHECK_NOTHROW(contessa.income()); //+1 
    CHECK_NOTHROW(captain2.foreign_aid()); //+2
    CHECK_NOTHROW(duke.coup(captain2)); // -7 -> capitan2 out of game
    CHECK_THROWS_MESSAGE(captain.block(duke), "cant block coup");
    

    /*check coins & players*/
    CHECK_EQ(ambassador.coins(), 2); 
    CHECK_EQ(duke.coins(), 0);
    CHECK_EQ(assassin.coins(), 1);
    CHECK_EQ(contessa.coins(), 5);
    CHECK_EQ(captain.coins(), 4);
    CHECK_EQ(game._size, 5);


    /*increase to 10 coins*/
    CHECK_NOTHROW(assassin.foreign_aid()); //+2
    CHECK_NOTHROW(ambassador.foreign_aid()); //+2
    CHECK_NOTHROW(captain.foreign_aid()); //+2
    CHECK_NOTHROW(contessa.foreign_aid()); //+2
    CHECK_NOTHROW(duke.tax()); //+3
    CHECK_NOTHROW(assassin.foreign_aid()); //+2
    CHECK_NOTHROW(ambassador.foreign_aid()); //+2
    CHECK_NOTHROW(captain.foreign_aid()); //+2
    CHECK_NOTHROW(contessa.foreign_aid()); //+2
    CHECK_NOTHROW(duke.tax()); //+3
    CHECK_NOTHROW(assassin.foreign_aid()); //+2
    CHECK_NOTHROW(ambassador.foreign_aid()); //+2
    CHECK_NOTHROW(captain.foreign_aid()); //+2
    CHECK_NOTHROW(contessa.foreign_aid()); //+2
    
    
    
    /*check coins & players*/
    CHECK_EQ(duke.coins(), 6);
    CHECK_EQ(ambassador.coins(), 8); 
    CHECK_EQ(assassin.coins(), 7);
    CHECK_EQ(contessa.coins(), 11);
    CHECK_EQ(captain.coins(), 10);
    
    
    /*move with 10 coins*/
    CHECK_NOTHROW(duke.block(contessa));
    CHECK_NOTHROW(duke.income()); //+1 
    CHECK_NOTHROW(assassin.income()); //+1
    CHECK_NOTHROW(ambassador.income()); //+1
    CHECK_THROWS_MESSAGE(captain.income(), "have 10 coins, must coup");
    CHECK_THROWS_MESSAGE(contessa.income(), "not your turn");
    CHECK_NOTHROW(captain.coup(assassin)); //-7
    CHECK_NOTHROW_MESSAGE(contessa.income(), "have 9 coins"); //+1
    CHECK_NOTHROW(duke.coup(contessa)); //-7
    CHECK_NOTHROW(ambassador.coup(duke)); //-7
    CHECK_THROWS_MESSAGE(assassin.income(), "not in game anymore");
    

    /*check coins & players*/
    CHECK_EQ(ambassador.coins(), 2); 
    CHECK_EQ(captain.coins(), 3);
    CHECK_EQ(game._size, 2);

    std::vector<std::string> players = game.players();
    CHECK_EQ(players[0], "tahel");
    CHECK_EQ(players[1], "renana");
    CHECK_EQ(players.size(), 2);
    

    /*2 players*/
    CHECK_THROWS_MESSAGE(game.winner(), "2 players left");
    CHECK_NOTHROW(captain.foreign_aid()); //+2
    CHECK_NOTHROW(ambassador.income()); //+1
    CHECK_NOTHROW(captain.steal(ambassador)); // +2, -2
    CHECK_NOTHROW(ambassador.income()); //+1
    CHECK_NOTHROW(captain.steal(ambassador)); // +1, -1
    CHECK_NOTHROW(ambassador.income()); //+1
    

    /*check coins & players*/
    CHECK_EQ(ambassador.coins(), 1); 
    CHECK_EQ(captain.coins(), 9);
    

    /*end game*/
    CHECK_NOTHROW(captain.coup(ambassador)); // -7
    CHECK_EQ(game.winner(), "renana");
    CHECK_EQ(game._size, 1);
    std::vector<std::string> players1 = game.players();
    CHECK_EQ(players1[0], "renana");
    
}

TEST_CASE("Bad Cases")
{
    SUBCASE("TOO-MUCH PLAYERS")
    {
        Game game_1{};
        Duke duke(game_1, "Moshe");
	    Assassin assassin{game_1, "Yossi"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        Duke duke2{game_1,"Gabi"};
        for(int i=0;i<10;i++)
        {
           switch(i%5){
               case 0: CHECK_THROWS(Duke duke3(game_1,"Fail")); break;
               case 1: CHECK_THROWS(Assassin assassin1(game_1,"Fail")); break;
               case 2: CHECK_THROWS(Ambassador ambassador1(game_1,"Fail")); break;
               case 3: CHECK_THROWS(Captain captain1(game_1, "Fail")); break;
               case 4: CHECK_THROWS(Contessa contessa1(game_1, "Fail")); break;
           }
        }
    }
    SUBCASE("TOO-FEW PLAYERS")
    {
        Game game_1{};
        Duke duke(game_1, "Moshe");
        for(int i=0;i<10;i++)
        {
            CHECK_THROWS(duke.income());
            CHECK_THROWS(duke.foreign_aid());
        }
    }
    SUBCASE("NOT PLAYERS TURN")
    {
        Game game_1{};
        Duke duke(game_1, "Moshe");
	    Assassin assassin{game_1, "Yossi"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        CHECK_THROWS(assassin.foreign_aid());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(captain.steal(duke));
        duke.income();
        CHECK_THROWS(contessa.foreign_aid());
    }
    SUBCASE("ILLEGAL ACTION")
    {
        Game game_1{};
        Duke duke(game_1, "Moshe");
	    Assassin assassin{game_1, "Yossi"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        CHECK_THROWS(duke.coup(assassin));
        duke.income();
        assassin.foreign_aid();
	ambassador.income();
        CHECK_THROWS(assassin.coup(duke));
        CHECK_THROWS(captain.block(duke));
        captain.steal(duke);
        CHECK_THROWS(contessa.block(assassin));
        contessa.income();
    }
}