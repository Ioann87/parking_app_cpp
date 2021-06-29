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
        }

        system("pause");
    }

    add_person(park);
    add_person(park);
    add_person(park);
    add_person(park);
    add_person(park);

    cout << park;

    //    park.set_persons(pers);

    //    cout << pers;

    //    cout << park;

    //    cout << endl;
    //    cout << pers;

    return 0;
}
