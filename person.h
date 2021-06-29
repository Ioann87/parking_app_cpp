#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;
    char gender;
    double cash;
    int volume;

public:
    Person();
    Person(const std::string, int, char, double, int);
    ~Person() {};
    void set_name(const std::string);
    std::string get_name();
    void set_age(int);
    int get_age();
    void set_gender(const char);
    char get_gender();
    void set_cash(double);
    double get_cash();
    void set_volume(int);
    int get_volume();

    double calc_cash(double);

    Person& operator=(const Person& pers);

    bool operator==(const Person& p2);

    bool operator!=(const Person& p2);

    bool operator<(const Person& p2);

    bool operator>(const Person& p2);

    friend std::ostream& operator<<(std::ostream& out, const Person& pers);

    friend std::istream& operator>>(std::istream& in, Person& pers);
};

#endif // PERSON_H
