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
		stringstream sLine;
		sLine << line;	
		while(!sLine.eof()){
			getline(sLine,attribute);
			cout << attribute << " ";
			//cout << endl;
			//row.push_back(attribute);
		}
		cout << endl;
	}
}
