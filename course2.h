#ifndef COURSE_H
#define COURSE_H

#include <string>
#include<iostream>
#include <iomanip>
using std::string;
using std::cout;
using std::endl;
using std::setw;
class Course {
public:
  Course(string a_title, string a_course_num, string a_section, string a_instructor, string a_day, string a_start_time, string a_end_time, string a_building, string a_room) {
    title = a_title;
    course_num = a_course_num;
    section = a_section;
    instructor = a_instructor;
    day = a_day;
    start_time = a_start_time;
    end_time = a_end_time;
    building = a_building;
    room = a_room;
  };
  string get_title(){ return title; };
  string get_course_num(){ return course_num; };
  string get_section(){ return section; };
  string get_instructor(){ return instructor; };
  string get_day(){ return day; };
  string get_start_time(){ return start_time; };
  string get_end_time(){ return end_time; };
  string get_building(){ return building; };
  string get_room(){ return room; };
  void print();
private:
  string title;
  string course_num;
  string section;
  string instructor;
  string day;
  string start_time;
  string end_time;
  string building;
  string room;
};

int comp_title(Course a, Course b) {
  return a.get_title() < b.get_title();
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

void Course::print(){
	// Variables used for formatting purposes
	int t_size = get_title().length();
	int cn_size = get_course_num().length();
	int s_size = get_section().length();
	int i_size = get_instructor().length();
	int d_size = get_day().length();
	int st_size = get_start_time().length();
	int et_size = get_end_time().length();
	int b_size = get_building().length();
	int r_size = get_room().length();
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

#endif
