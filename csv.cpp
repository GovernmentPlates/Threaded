#include "csv.h"

//CSV Processing function
//Accepts three params: fileIn (location of the CSV file), fileOut (name of the output CSV file)
void CSVUtils::processCSV(std::string fileIn, std::string fileOut) {
	std::lock_guard<std::mutex> guard(threadMutex); //Assign lock_guard to threadMutex
	std::cout << "[CSV Processor] Processing file (" << fileIn << ")... " << std::endl;
	std::ifstream readFile(fileIn); //Use ifstream to read the CSV
	std::ofstream writeFile(fileOut); //Use ofstream to write the results of the CSV

	//Using getline(), take in the CSV file, append the data from the CSV into fileData and separate it from the comma -- this becomes a single column CSV
	while (std::getline(readFile, fileData, ',')) {
		writeFile << fileData << std::endl; //For each line in the CSV, write the newly formatted CSV data into the output CSV (writeFile)
	}

	writeFile.close(); //Close the output CSV once we are done
	std::cout << "[CSV Processor] File processed: " << fileOut << std::endl; //Display a message to the console
	consoleUtils::taskbarAlert(); //Flash the taskbar icon (should the user minimize/tab-out of the console window)
}

//Basic (and somewhat terrible) CSV search function
//Accepts two params: fileIn (location of the CSV file), searchTerm (a term to find in the CSV)
void CSVUtils::searchCSV(std::string fileIn, std::string searchTerm) {
	std::cout << "[Search] Searching for '" << searchTerm << "'... " << std::endl;
	std::ifstream readFile(fileIn);
	
	while (std::getline(readFile, csvFieldOne, ',') && !termFound) {
		if (csvFieldOne.find(searchTerm) != std::string::npos) {
			termFound = true;
			std::cout << "[Search] Found '" << searchTerm << "'." << std::endl;
		}
	}
}