# pragma once
# include <iostream>
#include <deque>
#include <vector>
#include "Player.hpp"
#include <algorithm>
namespace coup{
    class Player;
    class Game
        {   
        public:  
            // std::vector<std::string> _players;
            std::vector<Player*> _players;
            size_t _currTurn;
            size_t _size; 
            Game();
            ~Game();
            std::string turn() const;
            std::vector<std::string> players() const;
            std::string winner() const;
            template <typename T>
            static bool contains(std::vector<T> vec, const T & elem);
        };
}


