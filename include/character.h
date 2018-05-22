#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    int maxBlock;
    int maxAttack;
    bool ai;
public:
    std::string name;
    int health;
    int lastMostPowerfulDamage = 0;
    Character(std::string, int, int, int, bool);
    int attack();
    int block();
    std::string toString();
};

Character::Character(std::string name, int health, int maxAttack, int maxBlock, bool ai){
        this->name = name;
        this->health = health;
        this->maxAttack = maxAttack;
        this->maxBlock = maxBlock;
        this->ai = ai;
}

int Character::attack(){
    return std::rand() % this->maxAttack;
}
int Character::block(){
    return std::rand() % this->maxBlock;
}

std::string Character::toString(){
    return name + "'s health is " + std::to_string(health);
}


#endif