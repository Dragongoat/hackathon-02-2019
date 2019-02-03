#include "filter.h"

vector<Course> add_filter(vector<Course> course_pool, vector<Filter> applied_filters, string filter_type, string specific) {
  // Check if filter is already applied

  vector<Course> updated_course_pool;

  if (filter_type == "title") {
    updated_course_pool = filter_title(course_pool, specific);
  }
  else if (filter_type == "number") {
    updated_course_pool = filter_number(course_pool, specific);
  }
  else if (filter_type == "instructor") {
    updated_course_pool = filter_instructor(course_pool, specific);
  }
  else if (filter_type == "day") {
    updated_course_pool = filter_day(course_pool, specific);
  }
  else if (filter_type == "time") {
    updated_course_pool = filter_time(course_pool, specific);
  }
  else if (filter_type == "building") {
    updated_course_pool = filter_building(course_pool, specific);
  }

  return updated_course_pool;
}

vector<Course> filter_title(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_title);

  int index = binSearchTitle(course_pool, target, 0, course_pool.size() - 1);

  // Finds first occurrence of the target
  while (index > 0 && course_pool[index].get_title() == target) {
    index--;
  }

  while (course_pool[index].get_title() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }

  return filtered;
}
vector<Course> filter_number(vector<Course> course_pool, string target) {
  vector<Course> filtered;
  return filtered;
}
vector<Course> filter_instructor(vector<Course> course_pool, string target) {
  vector<Course> filtered;
  return filtered;
}
vector<Course> filter_day(vector<Course> course_pool, string target) {
  vector<Course> filtered;
  return filtered;
}
vector<Course> filter_time(vector<Course> course_pool, string target) {
  vector<Course> filtered;
  return filtered;
}
vector<Course> filter_building(vector<Course> course_pool, string target) {
  vector<Course> filtered;
  return filtered;
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchTitle(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_title() > target) {
    return binSearchTitle(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_title() < target) {
    return binSearchTitle(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}
