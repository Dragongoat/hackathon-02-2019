#include "course.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::cin;
using std::getline;
using std::stringstream;


//Function declarations
//vector<Course> parseCSV();
void parseCSV();
int main(){
	parseCSV();

}


void parseCSV(){
	string line;
	string attribute;
	vector<string> row; // Used to store parsed data of each csv row
	ifstream inFile;
	inFile.open("./data.csv");
	getline(inFile,line);

	while(getline(inFile,line)){
		stringstream ss;
		ss << line;
		string title, course_num, section, instructor, day, time, building, room;
		// Get title
		if (ss.peek() == '"') {
			ss.ignore();
			getline(ss, title, '"');
			ss.ignore();
		}
		else {
			getline(ss, title, ',');
		}
		// Get Course number
		getline(ss, course_num, ',');
		// Get Section
		getline(ss, section, ',');
		// Get Instructor
		ss.ignore();
		getline(ss, instructor, '"');
		ss.ignore();
		// Get day
		getline(ss, day, ',');
		// Get time
		getline(ss, time, ',');
		// Get building
		getline(ss, building, ' ');
		// Get room
		getline(ss, room, ',');

		cout << title << " " << instructor << " " << building << " " << room << endl;
	}
}
