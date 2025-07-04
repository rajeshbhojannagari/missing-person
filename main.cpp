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

    // Read and insert persons
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
    inFile.close();

    // Write sorted persons by age to output.txt
    outFile << "📍 Sorted Missing Persons by Age:\n";
    tree.writeInOrder(outFile);

    // Read ID to search from search.txt
    ifstream searchFile("search.txt");
    if (searchFile.is_open()) {
        string searchId;
        getline(searchFile, searchId);
        searchFile.close();

        outFile << "\n🔍 Search Result for " << searchId << ":\n";
        Person* found = hashTable.search(searchId);
        if (found) {
            outFile << found->name << ", " << found->age << ", "
                    << found->gender << ", " << found->location << "\n";
        } else {
            outFile << "Person with ID " << searchId << " not found.\n";
        }
    } else {
        outFile << "\n⚠️ No search.txt found. Skipping search step.\n";
    }

    outFile.close();
    return 0;
}
