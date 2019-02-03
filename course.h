#ifndef COURSE_H
#define COURSE_H

#include <string>

using std::string;

struct instructor{
	string first_name;
	string last_name;
	instructor(string fn,string ln){
		first_name = fn;
		last_name = ln;
	}
	instructor(){
		first_name = "";
		last_name = "";
	}
};


class Course {
public:
  Course(string a_title, string a_major, string a_course_num, string a_section, instructor a_instructor, string a_day, string a_start_time, string a_end_time, string a_building, string a_room) {
    title = a_title;
    major = a_major;
    course_num = a_course_num;
    section = a_section;
    instru = a_instructor;
    day = a_day;
    start_time = a_start_time;
    end_time = a_end_time;
    building = a_building;
    room = a_room;
  };
  string get_title(){ return title; };
  string get_major() { return major; };
  string get_course_num(){ return course_num; };
  string get_section(){ return section; };
  string get_instructor(){ return (instru.first_name  + instru.last_name); };
  string get_day(){ return day; };
  string get_start_time(){ return start_time; };
  string get_end_time(){ return end_time; };
  string get_building(){ return building; };
  string get_room(){ return room; };
  void print();
private:
  string title;
  string major;
  string course_num;
  string section;
  instructor instru;
  string day;
  string start_time;
  string end_time;
  string building;
  string room;
};

int comp_title(Course a, Course b);
int comp_major(Course a, Course b);
int comp_number(Course a, Course b);
int comp_instructor(Course a, Course b);
int comp_day(Course a, Course b);
int comp_s_time(Course a, Course b);
int comp_e_time(Course a, Course b);
int comp_building(Course a, Course b);

#endif
