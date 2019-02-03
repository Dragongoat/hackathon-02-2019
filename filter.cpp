#include "filter.h"
#include <cctype>

using std::toupper;

vector<Course> add_filter(vector<Course> course_pool, vector<Filter> &applied_filters, string filter_type, string specific) {

  Filter adding_filter;
  adding_filter.type = filter_type;
  adding_filter.item_to_filter = specific;

  vector<Course> updated_course_pool;

  if (filter_type == "title") {
    updated_course_pool = filter_title(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "major") {
    updated_course_pool = filter_major(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "number") {
    updated_course_pool = filter_number(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "instructor") {
    updated_course_pool = filter_instructor(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "day") {
    for (int i = 0; i < (int)specific.size(); i++) {
      specific[i] = toupper(specific[i]);
    }
    updated_course_pool = filter_day(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "start_time") {
    updated_course_pool = filter_s_time(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "end_time") {
    updated_course_pool = filter_e_time(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }
  else if (filter_type == "building") {
    updated_course_pool = filter_building(course_pool, specific);
    if (updated_course_pool.size() == course_pool.size()) {
      cout << "ERROR: Entry not found, filter ignored\n";
      return course_pool;
    }
    applied_filters.push_back(adding_filter);
  }

  return updated_course_pool;
}

vector<Course> remove_filter(vector<Course> all_courses, vector<Filter> &applied_filters, string filter_type) {

    for (int i = 0; i < (int)applied_filters.size(); i++) {
      if (applied_filters[i].type == filter_type) {
        applied_filters[i] = applied_filters[applied_filters.size() - 1];
        applied_filters.resize(applied_filters.size() - 1);
      }
    }
    vector<Filter> app_filters;
    vector<Course> filtered = all_courses;

    for (int i = 0; i < (int)applied_filters.size(); i++) {
      filtered = add_filter(filtered, app_filters, applied_filters[i].type, applied_filters[i].item_to_filter);
    }

    return filtered;
}

vector<Course> filter_title(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_title);

  int index = binSearchTitle(course_pool, target, 0, course_pool.size() - 1);
  if (index == -1) {
    return course_pool;
  }

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
  if (index == -1) {
    return course_pool;
  }
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
  if (index == -1) {
    return course_pool;
  }
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
  if (index == -1) {
    return course_pool;
  }
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

  sort(course_pool.begin(), course_pool.end(), comp_day);

  int index = binSearchDay(course_pool, target, 0, course_pool.size() - 1);
  if (index == -1) {
    return course_pool;
  }
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_day() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_day() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_s_time(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_s_time);

  int index = binSearchSTime(course_pool, target, 0, course_pool.size() - 1);
  if (index == -1) {
    return course_pool;
  }
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_start_time() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_start_time() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_e_time(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_e_time);

  int index = binSearchETime(course_pool, target, 0, course_pool.size() - 1);
  if (index == -1) {
    return course_pool;
  }
  // Finds first occurrence of the target
  while (index > 0 && course_pool[index - 1].get_end_time() == target) {
    index--;
  }
  while (index < (int)course_pool.size() && course_pool[index].get_end_time() == target) {
    filtered.push_back(course_pool[index]);
    index++;
  }
  return filtered;
}
vector<Course> filter_building(vector<Course> course_pool, string target) {
  vector<Course> filtered;

  sort(course_pool.begin(), course_pool.end(), comp_building);

  int index = binSearchBuilding(course_pool, target, 0, course_pool.size() - 1);
  if (index == -1) {
    return course_pool;
  }
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
int binSearchDay(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_day() > target) {
    return binSearchDay(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_day() < target) {
    return binSearchDay(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchSTime(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_start_time() > target) {
    return binSearchSTime(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_start_time() < target) {
    return binSearchSTime(course_pool, target, mid + 1, high);
  }
  else {
    return mid;
  }
}

// This code based on binary search pseudocode at http://en.wikipedia.org/wiki/Binary_search
int binSearchETime(vector<Course> course_pool, string target, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (course_pool[mid].get_end_time() > target) {
    return binSearchETime(course_pool, target, low, mid - 1);
  }
  else if (course_pool[mid].get_end_time() < target) {
    return binSearchETime(course_pool, target, mid + 1, high);
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
