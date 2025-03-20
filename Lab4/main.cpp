#include <iostream>
#include "RPG.h"

using namespace std;

void displayStats(RPG player1, RPG player2) {
    cout << player1.getName() << " health: " << player1.getHealth() << " | "
         << player2.getName() << " health: " << player2.getHealth() << "\n";
}

void displayEnd(RPG player1, RPG player2) {
    if (player1.isAlive()) {
        cout << player1.getName() << " defeated " << player2.getName() << "! Good game!\n";
    } else {
        cout << player2.getName() << " defeated " << player1.getName() << "! Better luck next time.\n";
    }
}

void gameLoop(RPG* player1, RPG* player2) {
    while (player1->isAlive() && player2->isAlive()) {
        displayStats(*player1, *player2);
        
        cout << player1->getName() << "'s turn\n";
        player1->useSkill(player2);
        cout << "--------------------------------\n";
        if (!player2->isAlive()) break;
        
        cout << player2->getName() << "'s turn\n";
        player2->useSkill(player1);
        cout << "--------------------------------\n";
    }
}

int main() {
    RPG player("Wiz", 70, 45, 15, "mage");
    RPG npc;
    
    gameLoop(&player, &npc);
    displayEnd(player, npc);
    
    return 0;
}