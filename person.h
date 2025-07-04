#ifndef PERSON_H
#define PERSON_H
#include<string>
struct Person {
    std::string id;
    std::string name;
    int age;
    std::string gender;
    std::string location;
    Person() {}
    Person(std::string i, std::string n, int a, std::string g, std::string l)
        : id(i), name(n), age(a), gender(g), location(l) {}
};
#endif