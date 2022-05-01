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
        if(this->_size <=0){
            throw std::out_of_range("no players in game");
        }
        return this->_players[this->_currTurn]->getName();
    }

    /*Returns the names of the players currently active in the game*/
    std::vector<std::string> Game::players() const{
        if(this->_size <=0){
            throw std::out_of_range("no players in game");
        }
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
        if(this->_size <=0){
            throw std::out_of_range("there is no winner");
        }
        int counter =0;
        Player* win = this->_players[0];

        for (Player* p : this->_players)
        {
            if(p->getAlive()){
                counter++;
                win = p;
            }
        }
        if(counter > 1 || counter <1){
            throw std::out_of_range("there is no winner");
        }
        return win->getName();
        
    }


}