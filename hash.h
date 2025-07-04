#ifndef HASH_H
#define HASH_H
#include <unordered_map>
#include <string>
#include "person.h"
class PersonHashTable {
private:
    std::unordered_map<std::string, Person> table;
public:
    void insert(const Person& p) {
        table[p.id] = p;
    }
    Person* search(const std::string& id) {
        auto it = table.find(id);
        if (it != table.end())
            return &it->second;
        return nullptr;
    }
};
#endif