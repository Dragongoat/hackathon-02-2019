#ifndef COURSE_H
#define COURSE_H

#include <string>

using std::string;

class Course {
public:
  Course(string a_title, string a_course_num, int a_section, string a_instructor, string a_day, string a_time, string a_building, string a_room) {
    title = a_title;
    course_num = a_course_num;
    section = a_section;
    instructor = a_instructor;
    day = a_day;
    time = a_time;
    building = a_building;
    room = a_room;
  };
  string get_title(){ return title };
  string get_course_num(){ return course_num };
  int get_section(){ return section };
  string get_instructor(){ return instructor };
  string get_day(){ return day };
  string get_time(){ return time };
  string get_building(){ return building };
  string get_room(){ return room };
private:
  string title;
  string course_num;
  int section;
  string instructor;
  string day;
  string time;
  string building;
  string room;
};


#endif