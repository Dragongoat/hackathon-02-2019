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
using std::stoi;
using std::to_string;

//Function declarations
vector<Course> parseCSV(string fileName);
vector<string> parseTime(string time);
string convertTime(string time);

int main(){
	vector<Course> courseList;
	string csvFile = "data.csv";
	courseList = parseCSV(csvFile);
	for(int i = 0; i < courseList.size(); i++){
		courseList[i].print();
	}
	


	return 0;
}


vector<Course> parseCSV(string fileName){
	string line;
	string attribute;
	vector<Course> courseList;
	ifstream inFile;
	inFile.open(fileName);
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
		// Parse time into 24 hour and into start/end
		vector<string> timeArr;
		timeArr = parseTime(time);	
		// Get building
		getline(ss, building, ' ');
		// Get room
		getline(ss, room, ',');

		//store info into course class vector
		Course currentCourse = Course(title,course_num,section,instructor,day,timeArr[0],timeArr[1],building,room);
		courseList.push_back(currentCourse);

	}
	return courseList;
}

vector<string> parseTime(string time){
	vector<string> times;
	int end = time.length() -1;
	int s = time.find(" "); //space index

	string start_time = time.substr(0,s);
	string end_time = time.substr(s+1,end);
	times.push_back(convertTime(start_time));
	times.push_back(convertTime(end_time));
	return times;
}


string convertTime(string time){
	int time_end = time.length()-1;
	if(time[time_end-1] == 'A'){ // AM Class
		time = time.substr(0,time_end-1); // Remove AM characters
		if(time[0] == '1' && time[1] == '2') {
			time[0] = '0';
			time[1] = '0';
		}
	}
	else{ // PM Class
		time = time.substr(0,time_end-1); // remove PM characters
		if(!(time[0] == '1' && time[1] == '2')){ // if not noon, add 1200
			time = to_string(stoi(time) + 1200);
		}
	}
	return time;
}

/*void printCourseVector(vector<Course> cv){
    //Variables for width formatting
	int t_w = 28; 
    int cn_w = 8;
    int s_w = 4;
    int i_w = 35; 
    int d_w = 8;
    int st_w = 8;
    int et_w = 8;
    int b_w = 5;
    int r_w = 5;
	// end variables

}*/
