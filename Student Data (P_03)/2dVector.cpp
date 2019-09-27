#include "2dVector.h"

using namespace std;


vector <vector <string> > OrganizeData(string fileName) {
	//Opens the given file and splits up the contained data into rows of 6 elements, uses spaces and newlines.

	string line;
	ifstream myfile(fileName);

	vector <vector <string> > Data; //declaring a 2d vector with no declared size

	//making a vector with each element being an inner vector, outer vector will only be as big as it needs to be
	//inner vector will have a size of 6 and contain a students data
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			Data.resize(Data.size() + 1); //making an empty element in the outer vector
			Data.at(Data.size() - 1).resize(6); //making the inner vector the corect length

			stringstream stringData(line); //converting the string into a stream

			//entering each data point to their respective column
			stringData >> Data.at(Data.size() - 1).at(0);
			stringData >> Data.at(Data.size() - 1).at(1);
			stringData >> Data.at(Data.size() - 1).at(2);
			stringData >> Data.at(Data.size() - 1).at(3);
			stringData >> Data.at(Data.size() - 1).at(4);
			stringData >> Data.at(Data.size() - 1).at(5);

		}
		//The first data point always gets three wierd characters, so this cuts them off
		Data.at(0).at(0) = Data.at(0).at(0).substr(3);

		myfile.close();
	}
	return Data;
}

bool driver(vector<string> v1, vector<string> v2) {
	//Driver function for sorting 2D vector based on column
	int column = 3; //column index for cities
	return v1[column] < v2[column];
}

vector <vector <string> > DataByCity(vector <vector <string> > data) {
	//sorts the given 2d vector by the city column
	sort(data.begin(), data.end(), driver);
	return data;
}


void Display(vector <vector <string> > data) {
	//setting sizes for formating the data
	vector <int> textSizes(6, 0);
	textSizes.at(0) = 15;
	textSizes.at(1) = 10;
	textSizes.at(2) = 10;
	textSizes.at(3) = 20;
	textSizes.at(4) = 5;
	textSizes.at(5) = 10;

	//displays the given 2d Vector
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data.at(i).size(); j++) {
			cout << setw(textSizes.at(j)) << data.at(i).at(j);
		}
		cout << endl;
	}
	cout << endl; //extra line for making the text cleaner
}

void DisplaySortedData(vector <vector <string> > data) {
	//displays the given 2d vector sorted by cities
	Display(DataByCity(data));
}


void DisplayCityCount(vector <vector <string> > data) {
	data = DataByCity(data);
	Display(data);
	//should display the number of students from each city
	vector <string> studentCities;
	vector <int> numStudents;

	for (int i = 0; i < data.size(); i++) {//loop through each row of 2d data vector
		if (find(studentCities.begin(), studentCities.end(), data.at(i).at(3)) != studentCities.end()) {//if the city is already in the list, just add a student
			numStudents.at(numStudents.size() - 1) += 1;
		}
		else {// if the city is not in the list, add the city to the list and add a new element to start tracking students
			studentCities.push_back(data.at(i).at(3));//adding a new city

			numStudents.push_back(1);//adding new student
		}
	}

	for (int i = 0; i < studentCities.size(); i++) {
		cout << "***** We have " << numStudents.at(i) << " students from " << studentCities.at(i) << " this year *****\n";
	}
	cout << endl;
}