#include "course.h"

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
