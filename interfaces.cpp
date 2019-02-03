#include "interfaces.h"
#include "filter.h"

#define FORMAT_LINE "====================\n"

int menu_home(vector<Course> all_courses) {

  vector<string> options;
  options.push_back("Search");
  options.push_back("Current Classes");
  options.push_back("Today's Classes");
  options.push_back("Quit");

  bool quit = false;
  while (!quit) {
    cout << FORMAT_LINE;
    cout << "Main Menu:\n";
    cout << FORMAT_LINE << endl;
    int selection = Selection(options);

    switch(selection) {
      case 1:
        menu_search(all_courses);
        break;
      case 2:
        menu_current_classes();
        break;
      case 3:
        menu_todays_classes();
        break;
      case 4:
        quit = true;
        break;
    }
  }

  return 0;
}

int Selection(vector<string> options) {
  int num_options = options.size();
  int selection;
  do {
    selection_display(options);
    selection = get_selection(num_options);
    if (selection < 1 || selection > num_options) {
      cout << "ERROR: Selection must be between 1 and " << num_options << "\n\n";
    }
  }
  while (selection < 1 || selection > num_options);

  cout << endl;
  return selection;
}

void selection_display(vector<string> options) {
  for (int i = 0; i < (int)options.size(); i++) {
    cout << "(" << i + 1 << ") - " << options[i] << endl;
  }
}

int get_selection(int num_options) {
  cout << "\nSelection: ";
  int selection;
  cin >> selection;
  return selection;
}


int menu_search(vector<Course> all_courses) {

  vector<Course> filtered_courses = all_courses;
  vector<Filter> applied_filters;

  vector<string> options;
  options.push_back("Add new filter");
  options.push_back("Remove filter");
  options.push_back("Search course");
  options.push_back("Show all filtered courses");
  options.push_back("Quit");

  bool quit = false;
  while (!quit) {
    cout << FORMAT_LINE;
    cout << "Main Menu->Search:\n";
    cout << FORMAT_LINE;
    if (applied_filters.size() > 0) {
      cout << "\nCurrent filters: ";
    }
    for (int i = 0; i < (int)applied_filters.size(); i++) {
      cout << "<" << applied_filters[i].item_to_filter << "> ";
    }
    cout << endl;
    int selection = Selection(options);

    switch(selection) {
      case 1:
        string filter_type, target;
        specifyFilter(filter_type, target);
        filtered_courses = add_filter(filtered_courses, &applied_filters, filter_type, target);
        break;
      case 2:
        cout << "Remove filter called\n";
        break;
      case 3:
        cout << "Search courses called\n";
        break;
      case 4:
        for (int i = 0; i < (int)filtered_courses.size(); i++) {
          filtered_courses[i].print();
        }
        break;
      case 5:
        quit = true;
        break;
    }
  }


  return 0;
}

int menu_current_classes(vector<Course> all_courses) {
  vector<Filter> applied_filters;

  vector<string> options;
  options.push_back("Add new filter");
  options.push_back("Remove filter");
  options.push_back("Show current classes");
  options.push_back("Quit");

  bool quit = false;
  while (!quit) {
    cout << FORMAT_LINE;
    cout << "Main Menu->Current Classes:\n";
    cout << FORMAT_LINE;
    if (applied_filters.size() > 0) {
      cout << "\nCurrent filters: ";
    }
    for (int i = 0; i < (int)applied_filters.size(); i++) {
      cout << "<" << applied_filters[i].item_to_filter << "> ";
    }
    cout << endl;
    int selection = Selection(options);

    switch(selection) {
      case 1:
        cout << "Add new filter called\n";
        break;
      case 2:
        cout << "Remove filter called\n";
        break;
      case 3:
        cout << "Show current classes called\n";
        break;
      case 4:
        quit = true;
        break;
    }
  }

  return 0;
}

int menu_todays_classes(vector<Course> all_courses) {
  vector<Filter> applied_filters;

  vector<string> options;
  options.push_back("Add new filter");
  options.push_back("Remove filter");
  options.push_back("Show today's classes");
  options.push_back("Quit");

  bool quit = false;
  while (!quit) {
    cout << FORMAT_LINE;
    cout << "Main Menu->Today's Classes:\n";
    cout << FORMAT_LINE;
    if (applied_filters.size() > 0) {
      cout << "\nCurrent filters: ";
    }
    for (int i = 0; i < (int)applied_filters.size(); i++) {
      cout << "<" << applied_filters[i].item_to_filter << "> ";
    }
    cout << endl;
    int selection = Selection(options);

    switch(selection) {
      case 1:
        cout << "Add new filter called\n";
        break;
      case 2:
        cout << "Remove filter called\n";
        break;
      case 3:
        cout << "Show today's classes called\n";
        break;
      case 4:
        quit = true;
        break;
    }
  }

  return 0;
}

void specifyFilter(string &filter_type, string &target) {
  vector<string> options;
  options.push_back("Course Title");
  options.push_back("Course number");
  options.push_back("Instructor");
  options.push_back("Day");
  options.push_back("Time");
  options.push_back("Building");

  bool quit = false;
  while (!quit) {
    cout << FORMAT_LINE;
    cout << "What type of filter would you like to add?\n";
    cout << FORMAT_LINE;
    cout << endl;
    int selection = Selection(options);

    switch(selection) {
      case 1:
        filter_type = "title";
        cout << "Enter course title to filter: ";
        cin >> target;
        cin.flush();
        break;
      default:
        cout << "Currently unavailable\n";
        break;
    }
  }
}
