#ifndef INTERFACES_H
#define INTERFACES_H

#include "course.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int menu_home(vector<Course> all_courses);
int menu_search(vector<Course> all_courses);
int menu_current_classes(vector<Course> all_courses);
int menu_todays_classes(vector<Course> all_courses);
int Selection(vector<string> options);
void selection_display(vector<string> options);
int get_selection(int num_options);
void specifyFilter(string &filter_type, string &target);
void getTime(char &day, string &t);

#endif
