#include "include/isr.h"

isr interruptHandlers[256];

void registerIntHandler(uint8 n, isr handler){
	interruptHandlers[n] = handler;
}

void isrHandler(registers regs){
	if (interruptHandlers[regs.intNum] != 0){
		isr handler = interruptHandlers[regs.intNum];
		handler(regs);
	}else{
		// Print Error To Screen
	}
}

void irqHandler(registers regs){
	// Send EndOfInterrupt to PICs
	if (regs.intNum >= 40){
		outportb(0xA0, 0x20); // EOI to Slave
	}
	outportb(0x20, 0x20); // EOI to Master

	if (interruptHandlers[regs.intNum] != 0){
		isr handler = interruptHandlers[regs.intNum];
		handler(regs);
	}
}