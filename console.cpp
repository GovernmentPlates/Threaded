#include "console.h"

//Function to get the current timestamp (used in printTimestamp())
auto consoleUtils::getTimestamp() {
	auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	auto timeStamp = ctime(&timeNow);
	return timeStamp;
}

//Function to print the current time
void consoleUtils::printTimestamp() {
	std::cout << "Current Time: " << getTimestamp();
}

//Function used to print a demo message to the console
void consoleUtils::printDemoMsg() {
	std::cout << "[Multithreading Demo]" << std::endl;
	std::cout << "QUICK! Spam your WASD keys to change the console background colour." << std::endl;
}

//Function used to flash the console by momentarily changing the background and text colour of the console
void consoleUtils::flashConsole() {
	system("Color 6f");
	Sleep(500); //Sleep for half a second
	system("Color 0f");
	Sleep(500);
}

//Function used to flash the console taskbar icon (see line 18 on csv.cpp)
void consoleUtils::taskbarAlert() {
	//Ref: https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-flashwinfo
	FLASHWINFO flashTBInfo;
	//Define flash window members
	flashTBInfo.cbSize = sizeof(FLASHWINFO); //Set the size of the overall structure to that of the FLASHWINFO def
	flashTBInfo.hwnd = GetConsoleWindow(); //Use the GetConsoleWindow() to get the handle buffer of this application
	flashTBInfo.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG; //Set the flash status flags: FLASHW_ALL to flash both the window and taskbar (when the console is minimized/tabbed-out of view), FLASHW_TIMERNOFG to flash continously until the console comes back into view
	flashTBInfo.uCount = 10, flashTBInfo.dwTimeout = 0; //set uCount to 10 (flashes the window 10 times), set dwTimeout 0 (aka flash rate in milliseconds) to use the default cursor blink rate
	FlashWindowEx(&flashTBInfo); //Assign and pass all flash window members to FlashWindowEx
}