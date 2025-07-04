#include <iostream>
#include <fstream>
#include <sstream>
#include "person.h"
#include "bst.h"
#include "hash.h"
using namespace std;
int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening input/output file.\n";
        return 1;
    }
    BST tree;
    PersonHashTable hashTable;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string id, name, gender, location, ageStr;
        int age;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ','); age = stoi(ageStr);
        getline(ss, gender, ',');
        getline(ss, location);
        Person p(id, name, age, gender, location);
        tree.insert(p);
        hashTable.insert(p);
    }
    outFile << "📍 Sorted Missing Persons by Age:\n";
    tree.writeInOrder(outFile);
    outFile << "\n🔍 Sample Search for ID002:\n";
    Person* found = hashTable.search("ID002");
    if (found) {
        outFile << found->name << ", " << found->age << ", "
                << found->gender << ", " << found->location << "\n";
    } else {
        outFile << "Person with ID002 not found.\n";
    }
    inFile.close();
    outFile.close();
    return 0;
}
