#include "filter.h"

vector<Course> add_filter(vector<Course> course_pool, vector<Filter> &applied_filters, string filter_type, string specific) {

  Filter adding_filter;
  adding_filter.type = filter_type;
  adding_filter.item_to_filter = specific;

  vector<Course> updated_course_pool;

  if (filter_type == "title") {
    updated_course_pool = filter_title(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "major") {
    updated_course_pool = filter_major(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "number") {
    updated_course_pool = filter_number(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "instructor") {
    updated_course_pool = filter_instructor(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "day") {
    updated_course_pool = filter_day(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "time") {
    updated_course_pool = filter_time(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "building") {
    updated_course_pool = filter_building(course_pool, specific);
    applied_filters.push_back(adding_filter);
  }

  return updated_course_pool;
}

vector<Course> filter_title(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_title);

  int index = binSearchTitle(course_pool, target, 0, course_pool.size() - 1);

  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_title() == target) {
    index--;
  }

  while (course_pool[index].get_title() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }

  return filtered;
}
vector<Course> filter_major(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_major);

  int index = binSearchMajor(course_pool, target, 0, course_pool.size() - 1);
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_major() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_major() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_number(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_number);

  int index = binSearchNumber(course_pool, target, 0, course_pool.size() - 1);
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_course_num() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_course_num() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_instructor(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_instructor);

  int index = binSearchInstructor(course_pool, target, 0, course_pool.size() - 1);
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_instructor() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_instructor() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
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

  sort(course_pool.begin(), course_pool.end(), comp_building);

  int index = binSearchBuilding(course_pool, target, 0, course_pool.size() - 1);
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_building() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_building() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_room(vector<Course> course_pool, string target) {
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

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchMajor(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_major() > target) {
    return binSearchMajor(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_major() < target) {
    return binSearchMajor(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchNumber(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_course_num() > target) {
    return binSearchNumber(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_course_num() < target) {
    return binSearchNumber(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchInstructor(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_instructor() > target) {
    return binSearchInstructor(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_instructor() < target) {
    return binSearchInstructor(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchBuilding(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_building() > target) {
    return binSearchBuilding(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_building() < target) {
    return binSearchBuilding(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}
