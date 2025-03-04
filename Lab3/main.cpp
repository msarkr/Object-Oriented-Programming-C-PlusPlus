#include <iostream>
#include "RPG.h"

using namespace std;

int main() {
    RPG npc;
    RPG player("Wiz", 120, 15, 8, "mage");

    cout << "Welcome to the RPG Battle!\n\n";
    cout << player.getName() << " (Mage) vs " << npc.getName() << " (Warrior)\n";
    cout << player.getName() << " Health: " << player.getHealth() << " | " << npc.getName() << " Health: " << npc.getHealth() << "\n\n";

    while (player.isAlive() && npc.isAlive()) {
        cout << player.getName() << "'s turn\n";
        cout << "Skill 0: " << player.getSkill(0) << "\n";
        cout << "Skill 1: " << player.getSkill(1) << "\n";
        cout << "Choose a skill to use (Enter 0 or 1): ";
        
        int choice;
        cin >> choice;
        while (choice != 0 && choice != 1) {
            cout << "Invalid choice. Enter 0 or 1: ";
            cin >> choice;
        }

        player.attack(npc, choice);

        if (!npc.isAlive()) {
            cout << player.getName() << " defeated " << npc.getName() << "! Good game!\n";
            break;
        }

        int npc_choice = rand() % 2;
        cout << npc.getName() << "'s turn\n";
        npc.attack(player, npc_choice);

        if (!player.isAlive()) {
            cout << npc.getName() << " defeated " << player.getName() << "! Better luck next time.\n";
        }
    }

    return 0;
}
