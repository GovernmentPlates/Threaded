#include "keyboard.h"

//Process keyboard input function - used for demonstrating the multi-tasking (multi-threading)
void keyboardUtils::getKeyboardInput() {
	while (true) {
		char keyPress = _getch(); //Capture and assign all keyboard input to keyPress (using the __getch() func)

		//Switch statement for changing the colour of the console depending on pressing W, A, S or D
		switch (keyPress) {
		case 'w':
			system("Color 4f");
			break;
		case 'a':
			system("Color 5f");
			break;
		case 's':
			system("Color 6f");
			break;
		case 'd':
			system("Color 7f");
			break;
		}
	}
}