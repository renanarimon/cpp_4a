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

    CHECK_THROWS_MESSAGE(game.turn(), "no players in game");
    CHECK_THROWS_MESSAGE(game.winner(), "no players in game");

    Duke duke{game, "renana"};
	Assassin assassin{game, "talya"};
	Ambassador ambassador{game, "tahel"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "boaz"};
    Captain captain2{game, "shir"};

    CHECK(duke.coins() == 0);
    for (Player* p : game._players)
    {
        CHECK_EQ(p->coins(), 0);
    }

    CHECK_THROWS_MESSAGE(assassin.income(), "not assassign turn");
    CHECK_THROWS_MESSAGE(duke.block(captain), "can block only foreign_aid");
    CHECK_NOTHROW(duke.tax()); //+3
    
    
}