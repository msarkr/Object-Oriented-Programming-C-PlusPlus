#include "RPG.h"
#include <iostream>

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
string RPG::getSkill(int index) const { return (index == 0 || index == 1) ? skills[index] : "Invalid skill"; }

void RPG::updateHealth(int new_health) {
    health = (new_health < 0) ? 0 : new_health;
}

bool RPG::isAlive() const {
    return health > 0;
}

void RPG::attack(RPG &opponent, int attack_choice) {
    int damage = (attack_choice == 0) ? strength * 2 : strength * 3;
    damage -= opponent.getDefense();
    if (damage < 0) damage = 0;

    opponent.updateHealth(opponent.getHealth() - damage);

    cout << name << " used " << getSkill(attack_choice) << " on " << opponent.getName() << "!\n";
    cout << opponent.getName() << "'s health: " << opponent.getHealth() << "\n";
}
