#ifndef RPG_H
#define RPG_H

#include <string>

using namespace std;

class RPG {
private:
    string name;
    int health;
    int strength;
    int defense;
    string type;
    string skills[2];

    void setSkills();

public:
    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    string getSkill(int index) const;

    void updateHealth(int new_health);
    bool isAlive() const;
    void attack(RPG* opponent);
    void useSkill(RPG* opponent);
};

#endif