#include <iostream>
#include <vector>
#include <algorithm>
#include "game.h"

std::vector<Character> createCharacters(char* uc);

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
    for(auto c: characters) std::cout << c.toString() << "\n";
    return EXIT_SUCCESS;
}

// FUNCTIONS

std::vector<Character> createCharacters(char* uc){
    if (*uc == 'a') {
        Character knight ("Knight", 100, 40, 20, true);
        Character werewolf ("Werewolf", 150, 30, 15, true);
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
    else if(*uc == 'k') {
        Character knight ("Knight", 100, 40, 20, true);
        Character werewolf ("Werewolf", 150, 30, 15, true);
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
    else {
        Character knight ("Knight", 100, 40, 20, true);
        Character werewolf ("Werewolf", 150, 30, 15, true);
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
}

// ENDFUNCTIONS