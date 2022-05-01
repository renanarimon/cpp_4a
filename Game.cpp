#include "Game.hpp"
#include <exception>
namespace coup{
    Game::Game(){
        // std::vector<std::string> names;
        // this->_players = names;
        std::vector<Player*> p;
        this->_players = p;
        this->_currTurn=0;
        this->_size = 0;

    }
    Game::~Game(){}

    /*Print the name of the player whose turn to play now*/
    std::string Game::turn() const{
        return this->_players[this->_currTurn]->getName();
    }

    /*Returns the names of the players currently active in the game*/
    std::vector<std::string> Game::players() const{
        std::vector<std::string> names;
        for(Player* p : this->_players){
            if(p->getAlive()){
                names.push_back(p->getName());
            }
        }
        return names;
    }

    /*return the winner iff there is only one player left*/
    std::string Game::winner() const{
        int counter =0;
        Player* win = this->_players[0];

        for (size_t i = 0; i < this->_players.size(); i++)
        {
            if(this->_players[i]->getAlive()){
                counter++;
                win = this->_players[i];
            }
        }
        if(counter > 1 || counter <1){
            throw std::out_of_range("there is no winner");
        }
        return win->getName();
        
    }

    template <typename T>
    static bool contains(std::vector<T> vec, const T & elem)
    {
        if(std::find(vec.begin(), vec.end(), elem) != vec.end() )
        {
            return true;;
        }
        return false;
    }

}