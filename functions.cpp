#include "functions.h"
#include <cstring>
#include <fstream>

#include <string>

void add_names()
{
    init_names(female_names, name, PATH);
    init_names(male_names, name, PATH2);
    init_names(neutral_names, name, PATH3);
    return;
}

void init_names(
    std::vector<std::string>& names,
    std::string& name,
    const std::string& path)
{
    std::ifstream file(path);
    while (getline(file, name)) {
        names.push_back(name);
    }
    file.close();
    return;
}

Person init_person()
{
    Person pers;
    pers.set_gender(gender_var[rand() % strlen(gender_var)]);
    if (pers.get_gender() == 'm') {
        pers.set_name(male_names[rand() % 11]);
    } else if (pers.get_gender() == 'f') {
        pers.set_name(female_names[rand() % 11]);
    } else if (pers.get_gender() == '0') {
        pers.set_name(neutral_names[rand() % 7]);
    }
    pers.set_age(rand() % 70 + 20);
    pers.set_cash(rand() % 1000 + 2000 * 0.1);
    pers.set_volume(rand() % 3 + 1);
    return pers;
}

void menu()
{
    std::cout << "Welcome to parking application!" << std::endl;
    std::cout << "Select an action:" << std::endl;
    std::cout << "1 - add person; 2 - delete person;" << std::endl;
    std::cout << "3 - show all persons; " << std::endl;
    std::cout << "4 - exit. " << std::endl;
    return;
}

void add_person(Parking& park)
{
    Person temp;
    temp = init_person();
    park.set_persons(temp);
    return;
}

void del_person(Parking& park)
{
    std::cout << "Select parametrs: " << std::endl;
    std::cout << "1 - gender; 2 - age;" << std::endl;
    std::cout << "3 - volume; 4 - position;" << std::endl;
    std::cout << "0 - back. " << std::endl;
    int choice = 0;
    switch (choice) {
    case 1: {
        std::cout << "Select parametrs: " << std::endl;
        std::cout << "1 - m; 2 - f; 3 - '0'. " << std::endl;
        std::cout << "0 - exit. " << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            park.del_by_gen('m');
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 2: {
            park.del_by_gen('f');
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 3: {
            park.del_by_gen('0');
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 0:
            break;
        }
    }
    case 2: {
        std::cout << "Select parametrs: " << std::endl;
        std::cout << "1 - great; 2 - less; 3 - equal. " << std::endl;
        std::cout << "0 - exit. " << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int num = 0;
            std::cout << "great than: ";
            std::cin >> num;
            park.del_by_age('>', num);
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 2: {
            int num = 0;
            std::cout << "less than: ";
            std::cin >> num;
            park.del_by_age('<', num);
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 3: {
            int num = 0;
            std::cout << "equal: ";
            std::cin >> num;
            park.del_by_age('=', num);
            std::cout << "Persons has been deleted." << std::endl;
            break;
        }
        case 0:
            break;
        }
    }
    case 3: {
        std::cout << "Enter the volume you would like to remove: " << std::endl;
        std::cout << "1 ; 2 ; 3 . " << std::endl;
        std::cout << "0 - exit. " << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int num = 0;
            std::cout << "great than: ";
            std::cin >> num;
            park.del_by_volume('>', num);
            break;
        }
        case 2: {
            int num = 0;
            std::cout << "less than: ";
            std::cin >> num;
            park.del_by_age('<', num);
            break;
        }
        case 3: {
            int num = 0;
            std::cout << "equal: ";
            std::cin >> num;
            park.del_by_age('=', num);
            break;
        }
        case 0:
            break;
        }
    }
    case 4: {
        std::cout << "Enter position(1-50): ";
        int pos = 0;
        std::cin >> pos;
        park.del_pers(pos);
        std::cout << "Person has been deleted." << std::endl;
        break;
    }
    }

    return;
}
