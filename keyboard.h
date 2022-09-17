//keyboard.cpp header definitions
#pragma once
#include <conio.h> //Use conio.h to use the __getch() func
#include "console.h"

class keyboardUtils : public consoleUtils {
public:
	void getKeyboardInput(); //define getKeyboardInput func
};