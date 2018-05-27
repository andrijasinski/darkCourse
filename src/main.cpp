#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "game.h"

std::vector<Character> createCharacters(char* ua);
int evaluate(Character, Character);
char findBestMove(Character, Character);
int minimax(Character, Character, int, bool, int);

int main(int argc, char const *argv[])
{
    std::srand(std::time(NULL));
    std::cout << "Welcome to \"darkCourse\" game! Please, choose your character or let them fight on their own!\n";
    std::vector<char> keys = {'k', 'w', 'a'};
    std::vector<std::string> options = {
        "press [k] to play as a Knight",
        "press [w] to play as a Werewolf",
        "press [a] to let AI show it's power!"
    };
    char userAction;
    while (true) {
        std::cout << "Available options:\n";
        for(auto option: options) std::cout << option << "\n";
        std::cin >> userAction;
        if (std::cin.fail() || std::find(keys.begin(), keys.end(), userAction) == keys.end()) {
            std::cin.clear(); std::cin.ignore();
            std::cout << "Re-enter a valid value! ";
        } else break;
    }
    
    std::vector<Character> characters = createCharacters(&userAction);
    Character chr1 = characters[0];
    Character chr2 = characters[1];

    keys = {'a', 'h'};
    while(chr1.health > 0 && chr2.health > 0){
        std::cout << std::string(25, '=') << "\n";

        if (chr1.ai) {
            char action = findBestMove(chr1, chr2);
            if (action == 'a') {
                std::cout << chr1.name + " attacks. ";
                std::cout << chr2.applyDamage(chr1.attack()) << "\n";
            } else {
                std::cout << chr1.name + " decided to heal. ";
                std::cout << chr1.heal() << "\n";
            }
        } else {
            while (true) {
                std::cout << "Press [a] to attack or [h] to heal\n";
                std::cin >> userAction;
                if (std::cin.fail() || std::find(keys.begin(), keys.end(), userAction) == keys.end()) {
                    std::cin.clear(); std::cin.ignore();
                    std::cout << "Re-enter a valid value! \n";
                } else break;
            }
            if (userAction == 'a') {
                std::cout << chr1.name + " attacks. ";
                std::cout << chr2.applyDamage(chr1.attack()) << "\n";
            } else {
                std::cout << chr1.name + " decided to heal. ";
                std::cout << chr1.heal() << "\n";
            }
        }
        if (chr1.health <= 0 || chr2.health <= 0) break;
        if (chr2.ai) {
            char action = findBestMove(chr2, chr1);
            if (action == 'a') {
                std::cout << chr2.name + " attacks. ";
                std::cout << chr1.applyDamage(chr2.attack()) << "\n";
            } else {
                std::cout << chr2.name + " decided to heal. ";
                std::cout << chr2.heal() << "\n";
            }
        } else {
            while (true) {
                std::cout << "Press [a] to attack or [h] to heal\n";
                std::cin >> userAction;
                if (std::cin.fail() || std::find(keys.begin(), keys.end(), userAction) == keys.end()) {
                    std::cin.clear(); std::cin.ignore();
                    std::cout << "Re-enter a valid value! \n";
                } else break;
            }
            if (userAction == 'a') {
                std::cout << chr2.name + " attacks. ";
                std::cout << chr1.applyDamage(chr2.attack()) << "\n";
            } else {
                std::cout << chr2.name + " decided to heal. ";
                std::cout << chr2.heal() << "\n";
            }
        }
        if (chr1.health > 0 && chr2.health > 0) {
            std::cout << chr1.toString() << "\n";
            std::cout << chr2.toString() << "\n";   
        }
    }
    return EXIT_SUCCESS;
}

// FUNCTIONS

char findBestMove(Character chr1, Character chr2){
    Character chr1_copy ("1", chr1.health, chr1.getMaxAttack(), chr1.getMaxBlock(), chr1.ai); 
    Character chr2_copy ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 

    chr2_copy.applyDamage(chr1_copy.attack());
    int attackVal = minimax(chr1_copy, chr2_copy, 0, true, 20);

    Character chr2_copy_reset ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 
    chr1_copy.heal();
    int healVal = minimax(chr1_copy, chr2_copy_reset, 0, true, 20);

    char action = (healVal > attackVal) ? 'h' : 'a';
    return action;

}
int minimax(Character chr1, Character chr2, int depth, bool isMax, int maxDepth){
    int score = evaluate(chr1, chr2);
    if (score == 10 || score == -10 || depth == maxDepth) return score;

    if (isMax) {
        int best = -1000;
        Character chr1_copy ("1", chr1.health, chr1.getMaxAttack(), chr1.getMaxBlock(), chr1.ai); 
        Character chr2_copy ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 
        chr2_copy.applyDamage(chr1_copy.attack());
        best = std::max(best, minimax(chr1_copy, chr2_copy, depth+1, !isMax, maxDepth));
        
        Character chr2_copy_reset ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 
        chr1_copy.heal();
        best = std::max(best, minimax(chr1_copy, chr2_copy_reset, depth+1, !isMax, maxDepth));
        return best;
    } else {
        int best = 1000;
        Character chr1_copy ("1", chr1.health, chr1.getMaxAttack(), chr1.getMaxBlock(), chr1.ai); 
        Character chr2_copy ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 
        chr2_copy.applyDamage(chr1_copy.attack());
        best = std::min(best, minimax(chr1_copy, chr2_copy, depth+1, !isMax, maxDepth));
        
        Character chr2_copy_reset ("2", chr2.health, chr2.getMaxAttack(), chr2.getMaxBlock(), chr2.ai); 
        chr1_copy.heal();
        best = std::min(best, minimax(chr1_copy, chr2_copy_reset, depth+1, !isMax, maxDepth));
        return best;
    }
}

int evaluate(Character chr1, Character chr2){
    if (chr1.health <= 0) return -10;
    if (chr2.health <= 0) return 10;
    return chr1.health - chr2.health;
}

std::vector<Character> createCharacters(char* ua){
    Character knight ("Knight", 100, 45, 20, true);
    Character werewolf ("Werewolf", 250, 30, 15, true);
    if (*ua == 'a') {
        std::cout << "Knight and Werewolf are going to fight each other!\n";
        std::vector<Character> chr = {knight, werewolf};
        int r = std::rand() % 10;
        if (r < 5) {
            chr = {werewolf, knight};
        }
        return chr;
    }
    else if (*ua == 'k') {
        std::cout << "You are playing as a honourable Knight!\n";
        knight.ai = false;
        std::vector<Character> chr = {knight, werewolf};
        return chr;
    }
    else {
        std::cout << "You are playing as a mighty Werewolf!\n";
        werewolf.ai = false;
        std::vector<Character> chr = {werewolf, knight};
        return chr;
    }
}

// ENDFUNCTIONS