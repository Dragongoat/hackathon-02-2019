#include "interfaces.h"

#define FORMAT_LINE "====================\n"

int menu_home() {

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
        menu_search();
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


int menu_search() {

  vector<string> applied_filters;

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
      cout << "<" << applied_filters[i] << "> ";
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
        cout << "Search courses called\n";
        break;
      case 4:
        cout << "Show all filtered courses called\n";
        break;
      case 5:
        quit = true;
        break;
    }
  }


  return 0;
}

int menu_current_classes() {
  vector<string> applied_filters;

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
      cout << "<" << applied_filters[i] << "> ";
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

int menu_todays_classes() {
  vector<string> applied_filters;

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
      cout << "<" << applied_filters[i] << "> ";
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
