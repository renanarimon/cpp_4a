#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include "Player.hpp"
#include <algorithm>
namespace coup
{
    class Player;
    class Game
    {
    public:
        std::vector<Player *> _players;           // all players
        size_t _currTurn;                         // indx of this player turn
        size_t _size;                             // num of players in game now
        bool _started;
        Game();                                   // constructor
        ~Game();                                  // distructor
        std::string turn() const;                 // return name of this turn player
        std::vector<std::string> players() const; // return names of alive players
        std::string winner() const;               // return the winner
    };
}
