#include <iostream>
#include "game.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    Character knight ("Knight", 100, 40, 20, false);
    Character werewolf ("Werewolf", 150, 30, 15, true);

    return EXIT_SUCCESS;
}
