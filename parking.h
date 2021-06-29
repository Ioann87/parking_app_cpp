#ifndef PARKING_H
#define PARKING_H
#include <person.h>
#include <vector>

class Parking {
private:
    std::vector<Person> persons;
    std::vector<double> prices;
    double balance;
    int capacity;

public:
    Parking();
    ~Parking() {};
    void set_persons(Person);
    Person get_person(int);
    void set_prices(Person);
    double get_price(int);
    void set_capacity(Person);
    int get_capacity();

    void set_balance();
    double get_balance();

    double calc_price(Person);
    int calc_capacity(Person);
    double calc_balance();

    void del_pers(int);
    void del_by_gen(const char);

    friend std::ostream& operator<<(std::ostream& out, const Parking& park);
};

#endif // PARKING_H
