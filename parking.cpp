#include "parking.h"

Parking::Parking()
{
    balance = 0.0;
    capacity = 50;
}

void Parking::set_persons(Person pers)
{
    persons.push_back(pers);
    set_capacity(pers);
    set_prices(pers);
    set_balance();

    return;
}
Person Parking::get_person(int num)
{
    return persons.at(num);
}
void Parking::set_prices(Person pers)
{
    prices.push_back(calc_price(pers));
    return;
}
double Parking::get_price(int num)
{
    return prices.at(num);
}

void Parking::set_capacity(Person pers)
{
    this->capacity = calc_capacity(pers);
    return;
}
int Parking::get_capacity()
{
    return capacity;
}

int Parking::calc_capacity(Person pers)
{
    return capacity -= pers.get_volume();
}

double Parking::calc_price(Person pers)
{
    double price = 0.0;
    if (pers.get_gender() == 'm')
        price = (40 * 1.5 * 0.1 * pers.get_volume());
    else if (pers.get_gender() == 'f')
        price = (40 * 1.6 * 0.1 * pers.get_volume());
    else if (pers.get_gender() == '0')
        price = (40 * 1.7 * 0.1 * pers.get_volume());
    pers.set_cash(pers.calc_cash(price));
    return price;
}

void Parking::set_balance()
{
    this->balance = calc_balance();
    return;
}

double Parking::get_balance()
{
    return balance;
}

double Parking::calc_balance()
{
    double balance = 0.0;
    for (const auto& el : prices)
        balance += el;
    return balance;
}

void Parking::del_pers(int pos)
{
    std::vector<Person>::iterator it;
    it = persons.begin();
    std::advance(it, pos);
    persons.erase(it);
    return;
}

void Parking::del_by_gen(const char gen)
{
    std::vector<Person>::iterator it = persons.begin();
    for (size_t i = 0; i < persons.size(); i++, it++) {
        if (persons[i].get_gender() == gen) {
            persons.erase(it);
        }
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const Parking& park)
{
    std::cout << "Balance: " << std::endl;
    out << park.balance << std::endl;
    std::cout << "Capacity: " << std::endl;
    out << park.capacity << std::endl;

    std::cout << "Persons" << std::endl;
    for (const auto& el : park.persons) {
        out << el;
    }
    return out;
}
