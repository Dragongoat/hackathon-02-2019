#ifndef FILTER_H
#define FILTER_H

#include "course.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::sort;

class Filter {
public:
  string type;
  string item_to_filter;
};

vector<Course> add_filter(vector<Course> course_pool, vector<Filter> &applied_filters, string filter_type, string specific);
vector<Course> remove_filter(vector<Course> all_courses, vector<Filter> &applied_filters, string filter_type, string specific);
vector<Course> filter_title(vector<Course> course_pool, string target);
vector<Course> filter_major(vector<Course> course_pool, string target);
vector<Course> filter_number(vector<Course> course_pool, string target);
vector<Course> filter_instructor(vector<Course> course_pool, string target);
vector<Course> filter_day(vector<Course> course_pool, string target);
vector<Course> filter_s_time(vector<Course> course_pool, string target);
vector<Course> filter_e_time(vector<Course> course_pool, string target);
vector<Course> filter_building(vector<Course> course_pool, string target);
int binSearchTitle(vector<Course> course_pool, string target, int low, int high);
int binSearchMajor(vector<Course> course_pool, string target, int low, int high);
int binSearchNumber(vector<Course> course_pool, string target, int low, int high);
int binSearchInstructor(vector<Course> course_pool, string target, int low, int high);
int binSearchDay(vector<Course> course_pool, string target, int low, int high);
int binSearchSTime(vector<Course> course_pool, string target, int low, int high);
int binSearchETime(vector<Course> course_pool, string target, int low, int high);
int binSearchBuilding(vector<Course> course_pool, string target, int low, int high);


#endif
