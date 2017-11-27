#include "include/display.h"

uint32 cursorX = 0, cursorY = 0;
uint8 screenWidth = 80, screenHeight, screenD = 2;



void setCursor(int x, int y){
	cursorX = x;
	cursorY = y;
}

void advanceCursor(){
	cursorX++;
	if (cursorX >= screenWidth){
		cursorY++;
		cursorX = 0;
	}
}