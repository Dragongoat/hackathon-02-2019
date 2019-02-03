#include "course.h"
#include "interfaces.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

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
using std::chrono::system_clock;
//Function declarations
vector<Course> parseCSV(string fileName);
vector<string> parseTime(string time);
string convertTime(string time);
void getTime(char &day, string &t);

int main(){
	
/*	time_t tt = time(NULL);
	stringstream ss;
	ss << ctime(&tt);
	string time = ss.str();
	cout << time << endl;
	string day;
	getline(ss,day,' ');
	cout << day << endl;
	//cout << timeStr << endl;
*/
	
	vector<Course> courseList;
	string csvFile = "data.csv";
	courseList = parseCSV(csvFile);
	menu_home(courseList);



	return 0;
}


//Parses CSV file for courses information and stores in  vector of course object
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
		string title, course_major,course_num, section, instr_fn,instr_ln, day, time, building, room;
		// Get title
		if (ss.peek() == '"') {
			ss.ignore();
			getline(ss, title, '"');
			ss.ignore();
		}
		else {
			getline(ss, title, ',');
		}
		//Get Course major
		getline(ss,course_major,',');
		// Get Course number
		getline(ss, course_num, ',');
		// Get Section
		getline(ss, section, ',');
		// Get Instructor Last Name
		ss.ignore();
		getline(ss, instr_ln, ',');
		//Get Instructor First Name
		getline(ss,instr_fn,',');
		instr_fn.erase(instr_fn.length()-1,1);
		if(isupper(instr_fn[instr_fn.length()-1])){
			instr_fn.erase(instr_fn.length()-1,1);
		}
		//Store Instructor names into struct
		instructor instr(instr_fn,instr_ln);
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
		Course currentCourse = Course(title,course_major,course_num,section,instr,day,timeArr[0],timeArr[1],building,room);
		courseList.push_back(currentCourse);

	}
	return courseList;
}

//Parses time string into two strings and passes to convertTime function
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


//coverts a time in string format from 12 hour to 24 hour
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

void getTime(char &day, string &t){
	string curDay,garbage, curTime;
	stringstream ss;
	time_t tt = time(NULL);
	ss << ctime(&tt);
	//Get current day
	getline(ss,curDay,' ');
	//Getting rid of garbage values
	getline(ss,garbage,' ');
	getline(ss,garbage,' ');
	getline(ss,garbage,' ');
	// enf of garbage valies
	// Get time
	getline(ss,curTime,' ');
	curTime.erase(2,1);
	curTime.erase(4,3);
	if(curDay[0] != 'T'){
		day = curDay[0];
	}	
	else{
		if(curDay[1] == 'u') day = 'T';
		else day = 'R';
	}

	t = curTime;
}
