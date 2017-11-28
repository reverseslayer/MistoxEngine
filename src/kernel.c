#include "include/multiboot.h"
#include "include/descTables.h"
#include "include/asmFuncts.h"

// Drivers

#include "include/display.h"

int kernel_main( struct multiboot* mboot ) {
	
	//clearScreen();

	initDescTbls();			// Setup Interrupts
	__asm__ __volatile__("sti");	// Set Interrupt Flag

	//initTimer(50);
	//initKeyboard();
	//initShell();

	return 0;
}
