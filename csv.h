//csv.cpp header definitions
#pragma once
#ifndef CSV_H
#define CSV_H

#include "console.h" //Include console.h to access funcs from there
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <mutex>

class CSVUtils : public consoleUtils {
public:
	std::string fileIn, fileOut, fileData, searchTerm, csvFieldOne; //Define strings
	std::mutex threadMutex; //Define mutex
	bool termFound = false; //Define boolean (used in searchCSV() func)
	void processCSV(std::string fileIn, std::string fileOut); //Define processCSV func
	void searchCSV(std::string fileIn, std::string searchTerm); //Define searchCSV func
};

#endif // !CSV_H