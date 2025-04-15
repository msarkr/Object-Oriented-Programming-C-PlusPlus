#include <iostream>
#include "Charmander.h"
using namespace std;

int main() {
    // Create a Charmander object with custom attributes
    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "\n-------- Constructor Created --------\n";
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType, skills);

    // Direct object method call
    cout << "\n-------- Direct Speak --------\n";
    charlie.speak();

    // Base class pointer to derived class
    Pokemon *p1 = &charlie;
    cout << "\n-------- Speak called from Pokemon Pointer --------\n";
    p1->speak();

    // Derived class pointer to derived class
    Charmander *c1 = &charlie;
    cout << "\n-------- Speak called from Charmander Pointer --------\n";
    c1->speak();

    // Print stats
    cout << "\n-------- Print Stats --------\n";
    charlie.printStats();

    return 0;
}
