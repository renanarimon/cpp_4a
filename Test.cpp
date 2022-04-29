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
    Game game_1;
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    Captain captain{game_1, "shira"};

    /*game can't have 2 players with same name*/
    try
    {
        Duke duke{game_1, "Moshe"};
        CHECK_FALSE_MESSAGE(true, "game can't have 2 players with same name");
        Captain captain{game_1, "Moshe"};
        CHECK_FALSE_MESSAGE(true, "game can't have 2 players with same name");
    }
    catch(const std::exception& e)
    {
        CHECK_FALSE(false);
    }

    duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();

    /*income() added 1 coin*/
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 1);
    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 1);


    CHECK_THROWS_MESSAGE(contessa.block(captain), "nothing to block");
    CHECK_THROWS_MESSAGE(assassin.foreign_aid(), "not your turn");

    duke.tax(); // +3 coins ->4
    assassin.foreign_aid(); // +2 ->3
    ambassador.income(); // +1 ->2
	CHECK_THROWS_MESSAGE(captain.steal(contessa), "other player doesn't have 2 coins");
    captain.steal(ambassador); // +2 -> 4 //amb -2 -> 0
	contessa.foreign_aid(); // +2 ->3
    ambassador.block(captain); // amb +2 -> 2 //cap -2 ->

    CHECK_THROWS_MESSAGE(duke.coup(contessa), "not enought coins"); // Prohibited action, therefore not considered, try your turn again
    CHECK_THROWS_MESSAGE(assassin.income(), "not your turn");

    duke.tax(); // +3 coins -> 7







    



}