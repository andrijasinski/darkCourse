#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    int maxBlock;
    int maxAttack;
    int healPoints;
    bool ai;
public:
    std::string name;
    int health;
    Character(std::string, int, int, int, bool);
    int attack();
    int block();
    std::string applyDamage(int);

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

std::string Character::applyDamage(int damage){
    int blockedDamage = damage - block();
    std::string message;
    if (blockedDamage > 0) {
        health -= blockedDamage;
        message = name + " received " + std::to_string(blockedDamage) + " points of damage. " + toString();
    }
    else {
        message = name + " blocked attack!";
    }
    return message;
}

std::string Character::toString(){
    return name + "'s health is " + std::to_string(health);
}


#endif