#ifndef PERSON_HPP
#define PERSON_HPP
#include <cstring>
#include <iostream>

using namespace std;
class Person {
public:
    string name = "";
    string surname = "";
    int day = 0;
    int month = 0;
    int year = 0;

    Person(string name, string surname, int day, int month, int year)
    {
        this->name = name;
        this->surname = surname;
        this->day = day;
        this->month = month;
        this->year = year;
    }
};


std::ostream &operator<<(std::ostream &out, const Person& element) {
    for (auto k:element.surname)
        out<<k;
    std::cout<<" ";
    for (auto k:element.name)
        out<<k;
    out<<"  "
       <<element.day
       <<"."
       <<element.month
       <<"."
       <<element.year;
    return out;
}


bool operator==(const Person& p1, const Person& p2) {
    if (p1.year==p2.year) {
        return true;
    }
    else{
        return false;
    }

}


bool operator<(const Person& p1, const Person& p2) {
    if (p1.year>p2.year){
        return true;
    }
    else{
        return false;
    }
}

bool operator>(const Person& p1, const Person& p2) {
    if (p1.year<p2.year){
        return true;
    }
    else{
        return false;
    }
}
#endif //PERSON_HPP
