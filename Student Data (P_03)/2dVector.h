#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm> //for std::sort and std:find
#include <string>
#include <vector>
#include <iomanip> // for std:setw()

using namespace std;


vector <vector <string> > OrganizeData(string fileName); //Opens the given file and splits up the contained data into rows of 6 elements, uses spaces and newlines.

void Display(vector <vector <string> > data); //setting sizes for formating the data

void DisplaySortedData(vector <vector <string> > data); //displays the given 2d vector sorted by cities

void DisplayCityCount(vector <vector <string> > data); //should display the number of students from each city