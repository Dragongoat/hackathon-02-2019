#ifndef INTERFACES_H
#define INTERFACES_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int menu_home();
int menu_search();
int menu_current_classes();
int menu_todays_classes();
int Selection(vector<string> options);
void selection_display(vector<string> options);
int get_selection(int num_options);

#endif
