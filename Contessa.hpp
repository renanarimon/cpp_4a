# pragma once
#include"Player.hpp"
namespace coup{
    class Contessa : public Player
    {
    private:
        /* data */
    public:
        Contessa(Game &game, std::string name);
        ~Contessa();
        static void block(Player &p); //block coup
    };
}


