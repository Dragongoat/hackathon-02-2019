#include "course.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

void Course::print() {
  // Variables used for formatting purposes
	int t_size = get_title().length();
	int cn_size = get_course_num().length();
	int s_size = get_section().length();
	int i_size = get_instructor().length();
	int d_size = get_day().length();
	int st_size = get_start_time().length();
	int et_size = get_end_time().length();
	int t_w = 40;
	int cn_w = 8;
	int s_w = 4;
	int i_w = 35;
	int d_w = 8;
	int st_w = 8;
	int et_w = 8;
	int b_w = 5;
	int r_w = 5;
	// end variables


	cout << get_title() << setw(t_w-t_size)<< " " << get_course_num() << setw(cn_w - cn_size) << " " << get_section();
	cout << setw(s_w - s_size) << " " << get_instructor()<< setw(i_w - i_size) << " " << get_day() << setw(d_w - d_size) << " " << get_start_time();
	cout << setw(st_w - st_size) << " " << get_end_time() <<  setw(et_w - et_size)  << " " << setw(b_w) << get_building();
	cout << setw(r_w) << " " << get_room() << endl;
}

int comp_title(Course a, Course b) {
  return a.get_title() < b.get_title();
}

int comp_major(Course a, Course b) {
  return a.get_major() < b.get_major();
}

int comp_number(Course a, Course b) {
  return a.get_course_num() < b.get_course_num();
}

int comp_instructor(Course a, Course b) {
  return a.get_instructor() < b.get_instructor();
}

int comp_building(Course a, Course b) {
  return a.get_building() < b.get_building();
}
