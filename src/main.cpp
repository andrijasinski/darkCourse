#include <iostream>
#include <vector>
#include <algorithm>
#include "game.h"

std::vector<Character> createCharacters(char* uc);
std::vector<Character> evaluate(char action, Character attacker, Character blocker);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    std::cout << "Welcome to \"darkCourse\" game! Please, choose your character or let fight on their own!\n";
    std::vector<char> keys = {'k', 'w', 'a'};
    std::vector<std::string> options = {
        "press [k] to play as a Knight",
        "press [w] to play as a Werewolf",
        "press [a] to let AI show it's power!"
    };
    char userCharacter;
    while (true) {
        std::cout << "Available options:\n";
        for(auto option: options) std::cout << option << "\n";
        std::cin >> userCharacter;
        if (std::cin.fail() || std::find(keys.begin(), keys.end(), userCharacter) == keys.end()) {
            std::cin.clear(); std::cin.ignore();
            std::cout << "Re-enter a valid value! ";
        } else break;
    }
    
    std::vector<Character> characters = createCharacters(&userCharacter);
    Character chr1 = characters[0];
    Character chr2 = characters[1];

    keys = {'a', 'h'};
    while(chr1.health > 0 && chr2.health > 0){
        if (chr1.ai) {
            /* code */
        } else {
            while (true) {
                std::cout << "Press [a] to attack or [h] to heal\n";
                std::cin >> userCharacter;
                if (std::cin.fail() || std::find(keys.begin(), keys.end(), userCharacter) == keys.end()) {
                    std::cin.clear(); std::cin.ignore();
                    std::cout << "Re-enter a valid value! \n";
                } else break;
            }
            if (userCharacter == 'a') {
                std::cout << chr1.name + " attacks. ";
                std::cout << chr2.applyDamage(chr1.attack()) << "\n";
            } else {
                std::cout << chr1.name + " decided to heal. ";
                std::cout << chr1.heal() << "\n";
            }
        }
        if (chr2.ai) {
            /* code */
        } else {
            while (true) {
                std::cout << "Press [a] to attack or [h] to heal\n";
                std::cin >> userCharacter;
                if (std::cin.fail() || std::find(keys.begin(), keys.end(), userCharacter) == keys.end()) {
                    std::cin.clear(); std::cin.ignore();
                    std::cout << "Re-enter a valid value! \n";
                } else break;
            }
            if (userCharacter == 'a') {
                std::cout << chr1.name + " attacks. ";
                std::cout << chr2.applyDamage(chr1.attack()) << "\n";
            } else {
                std::cout << chr1.name + " decided to heal. ";
                std::cout << chr1.heal() << "\n";
            }
        }
        
    }
    

    return EXIT_SUCCESS;
}

// FUNCTIONS

std::vector<Character> evaluate(char action, Character attacker, Character blocker){
    std::vector<Character> newStats;
    if (action == 'a'){ // attack
        blocker.applyDamage(attacker.attack());
    } else // heal
    {
        attacker.heal();
    }
    std::vector<Character> chrs = {attacker, blocker};
    return chrs;
}

std::vector<Character> createCharacters(char* uc){
    if (*uc == 'a') {
        Character knight ("Knight", 100, 35, 20, true);
        Character werewolf ("Werewolf", 150, 30, 15, true);
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
    else if (*uc == 'k') {
        Character knight ("Knight", 100, 35, 20, false);
        Character werewolf ("Werewolf", 150, 30, 15, true);
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
    else {
        Character knight ("Knight", 100, 35, 20, true);
        Character werewolf ("Werewolf", 150, 30, 15, false);
        std::vector<Character> chr = {werewolf, knight};
        return chr;
    }
}

// ENDFUNCTIONS