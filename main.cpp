#include "console.h"
#include "csv.h"
#include "keyboard.h"
#include <future>

int main() {
	consoleUtils console;
	CSVUtils csv;
	keyboardUtils keyboard;

	console.printDemoMsg(); //print the demo message to the console

	//Use future to create an async process for the processCSV function, and ensure that it runs on it's own thread (by using std::launch::async)
	std::future<void> csvAsyncProcess = std::async(std::launch::async, [&] {csv.processCSV("unigram_freq.csv", "result.csv"); }); //Note: Remember to place the unigram_freq.csv in your build directory first!

	//Spawn a thread for displaying the time
	std::thread trDisplayTime([&] {
		console.printTimestamp(); //call the printTimestamp func
	});

	//Spawn a thread for 'flashing' the background colour of our console
	std::thread trFlashWindow([&] {
		console.flashConsole(); //call the flashConsole func
	});

	//Spawn a thread for changing the colour of the console background
	std::thread trKeyboardColourChanger([&] {
		keyboard.getKeyboardInput(); //call the getKeyboardInput func
	});

	//Spawn a thread for searching the CSV
	std::thread trSearchCSV([&] {
		csv.searchCSV("unigram_freq.csv", "demonstration"); //call the searchCSV func
	});

	//Join all threads together
	trDisplayTime.join();
	trFlashWindow.join();
	trKeyboardColourChanger.join();
	trSearchCSV.join();

	/*

	//Used for measuring the time taken to process (debug) - uncomment and place start and stop between sections of the code that you wish to measure

	auto start = std::chrono::high_resolution_clock::now();

	auto stop = std::chrono::high_resolution_clock::now();

	double processTime = (std::chrono::duration<double, std::milli>(stop - start).count());
	std::cout << "Time taken to process: " << processTime << " ms (" << processTime / 1000 << " sec)" << std::endl;
	
	*/

	return 0;
}