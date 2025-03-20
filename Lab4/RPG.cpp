#include "RPG.h"
#include <iostream>
#include <algorithm>

using namespace std;

RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    setSkills();
}

RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();
}

void RPG::setSkills() {
    if (type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

string RPG::getName() const { return name; }
int RPG::getHealth() const { return health; }
int RPG::getStrength() const { return strength; }
int RPG::getDefense() const { return defense; }
string RPG::getSkill(int index) const { return (index >= 0 && index < 2) ? skills[index] : "Invalid skill"; }

void RPG::updateHealth(int new_health) {
    health = (new_health < 0) ? 0 : new_health;
}

bool RPG::isAlive() const {
    return health > 0;
}

void RPG::attack(RPG* opponent) {
    int damage = max(0, strength - opponent->getDefense());
    opponent->updateHealth(opponent->getHealth() - damage);
}

void RPG::useSkill(RPG* opponent) {
    for (int i = 0; i < 2; i++) {
        cout << "Skill " << i << ": " << skills[i] << "\n";
    }
    cout << "Choose a skill to use: Enter 0 or 1\n";
    
    int choice;
    cin >> choice;
    while (choice != 0 && choice != 1) {
        cout << "Invalid choice. Enter 0 or 1: ";
        cin >> choice;
    }
    
    cout << name << " used " << skills[choice] << " on " << opponent->getName() << "!\n";
    attack(opponent);
    cout << opponent->getName() << "'s health: " << opponent->getHealth() << "\n";
}
