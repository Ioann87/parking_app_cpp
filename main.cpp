#include <cstring>
#include <ctime>
#include <fstream>
#include <functions.h>
#include <iostream>
#include <parking.h>
#include <person.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));

    add_names();

    Parking park;
    std::cout << "Welcome to parking application!" << std::endl;
    while (true) {
        menu();
        int choice = 0;
        cin >> choice;
        switch (choice) {
        case 1:
            add_person(park);
            break;
        case 2:
            del_person(park);
            break;
        case 3:
            show_statistic(park);
            break;
        case 4:
            cout << park;
            break;
        case 0:
            exit(0);
        }

        system("pause");
    }
    return 0;
}
