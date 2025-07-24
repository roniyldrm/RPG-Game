#pragma once
#include "Entity.hpp"

class Player : public Entity{
    private:
        void initVars();
        void initComponents();
    protected:

    public:
        Player(sf::Vector2f pos, sf::Texture* texture);
        virtual ~Player();
};

