//console.cpp header definitions
#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <Windows.h> //Include Windows.h to use Sleep()

class consoleUtils {
public:
	auto getTimestamp();
	void printTimestamp();
	void printDemoMsg();
	void flashConsole();
	void taskbarAlert();
};

#endif // !CONSOLE_H