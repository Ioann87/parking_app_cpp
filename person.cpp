#include "person.h"
#include <cstring>

Person::Person()
{
    name = "";
    age = 0;
    gender = '\0';
    cash = 0.0;
    volume = 0;
}

Person::Person(
    const std::string name,
    int age,
    char gender,
    double cash,
    int volume)
{
    set_name(name);
    set_age(age);
    set_gender(gender);
    set_cash(cash);
    set_volume(volume);
}

void Person::set_name(const std::string name)
{
    this->name = name;
    return;
}
std::string Person::get_name()
{
    return name;
}
void Person::set_age(int age)
{
    this->age = age;
    return;
}
int Person::get_age()
{
    return age;
}
void Person::set_gender(const char gender)
{
    this->gender = gender;
    return;
}
char Person::get_gender()
{
    return gender;
}
void Person::set_cash(double cash)
{
    this->cash = cash;
    return;
}
double Person::get_cash()
{
    return cash;
}
void Person::set_volume(int volume)
{
    this->volume = volume;
    return;
}
int Person::get_volume()
{
    return volume;
}

double Person::calc_cash(double price)
{
    double cash = 0.0;
    cash -= price;
    return cash;
}

Person& Person::operator=(const Person& pers)
{
    this->name = pers.name;
    this->age = pers.age;
    this->gender = pers.gender;
    this->cash = pers.cash;
    this->volume = pers.volume;

    return *this;
}

bool Person::operator==(const Person& p2)
{
    if (this->age == p2.age)
        return true;
    else
        return false;
}

bool Person::operator!=(const Person& p2)
{
    if (this->age != p2.age)
        return true;
    else
        return false;
}

bool Person::operator<(const Person& p2)
{
    if (this->age < p2.age)
        return true;
    else
        return false;
}

bool Person::operator>(const Person& p2)
{
    if (this->age > p2.age)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& out, const Person& pers)
{
    out << "Name: " << pers.name << std::endl;
    out << "Age: " << pers.age << std::endl;
    out << "Gender: " << pers.gender << std::endl;
    out << "Cash: " << pers.cash << std::endl;
    out << "Volume: " << pers.volume << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Person& pers)
{
    std::cout << "enter name: ";
    in >> pers.name;
    std::cout << "enter age: ";
    in >> pers.age;
    std::cout << "enter gender(m/f/0): ";
    in >> pers.gender;
    in.ignore();
    std::cout << "enter cash: ";
    in >> pers.cash;
    std::cout << "enter volume: ";
    in >> pers.volume;
    return in;
}
