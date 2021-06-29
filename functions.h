#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <parking.h>
#include <person.h>
#include <string>
#include <vector>

inline const char* gender_var = "mf0";

inline std::vector<std::string> female_names;
inline std::string PATH = "/home/shastiva/c_projects/homework25/female";
inline std::vector<std::string> male_names;
inline std::string PATH2 = "/home/shastiva/c_projects/homework25/male";
inline std::vector<std::string> neutral_names;
inline std::string PATH3 = "/home/shastiva/c_projects/homework25/neutrum";
inline std::string name;

void add_names();

void init_names(std::vector<std::string>&, std::string&, const std::string&);

Person init_person();

void menu();

void add_person(Parking&);

void del_person(Parking&);

#endif // FUNCTIONS_H
