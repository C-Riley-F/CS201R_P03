//Riley Frazier
//Program 03
//9-26-19

#include "2dVector.h"

int getAnswer() {
	int answer = 0;
	int loop = 0;
	while (answer < 1 || answer > 4 ){
		if (loop != 0) { //this wont run the first loop, but will run every other loop untill the user enters a valid number
			cout << "Please enter a valid number.\n";
		}
		cout << "Welcome to Student Center\n";
		cout << "1- Display Student Info\n";
		cout << "2- Display Student Info sorted by city\n";
		cout << "3- Display Student Info sorted by city and Total number of students per City\n";
		cout << "4- Exit\n";

		cout << "Please choose an option:\n";
		cin >> answer;
		cout << endl;
		
		loop++; //counting the loop
	}
	return answer;
}

int Menu(vector <vector <string> >dataVector) {
	//gets the user's answer
	int answer = getAnswer();

	//runs function depending on input
	switch (answer)
	{
	case 1:
		Display(dataVector);
		break;
	case 2:
		DisplaySortedData(dataVector);
		break;
	case 3:
		DisplayCityCount(dataVector);
		break;
	}
	return answer;
	
}

int main() {
	vector <vector <string> > studentData = OrganizeData("Student_Info.txt");
	
	while (true){//goes until user enters 4
		int answer = Menu(studentData);
		if (answer == 4) {
			break;
		}	
	}
	return 0;
}