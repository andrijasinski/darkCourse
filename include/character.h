#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    int maxBlock;
    int maxAttack;
    int maxHealth;
public:
    bool ai;
    std::string name;
    int health;
    Character(std::string, int, int, int, bool);
    int attack();
    int block();
    std::string applyDamage(int);
    std::string heal();
    std::string toString();
    int getMaxAttack();
    int getMaxBlock();
};

Character::Character(std::string name, int health, int maxAttack, int maxBlock, bool ai){
        this->name = name;
        this->health = health;
        this->maxHealth = health;
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
    if (health - blockedDamage <= 0){
        health = -1;
        message = name +" received " + std::to_string(blockedDamage) + " points of damage. ";
        message += name + " died.";
    } else if (blockedDamage > 0) {
        health -= blockedDamage;
        message = name + " received " + std::to_string(blockedDamage) + " points of damage. " + toString();
    } else {
        message = name + " blocked attack!";
    }
    return message;
}

std::string Character::heal(){
    int toHeal = std::rand() % 20;
    std::string message;
    if (health + toHeal >= this->maxHealth){
        health = this->maxHealth;
        message = name + " fully restored his health!";
    } else {
        health += toHeal;
        message = toString();
    }
    return message;
}

std::string Character::toString(){
    return name + "'s health is " + std::to_string(health) + ".";
}

int Character::getMaxAttack(){
    return this->maxAttack;
}

int Character::getMaxBlock(){
    return this->maxBlock;
}

#endif