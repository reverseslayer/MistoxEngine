#ifndef descTables_h
#define descTables_h

#include "asmFuncts.h"
#include "memory.h"
#include "isr.h"

void initDescTbls();

struct gdtEntry_t{
	uint16 limitLow;		// Lower 16 bits of limit
	uint16 baseLow;			// Lower 16 bits of base
	uint8 baseMiddle;		// Next 8 bits of base
	uint8 flags;			// Access flags, ( Rings )
	uint8 granularity;
	uint8 baseHigh;		// Last 8 bits of base
}__attribute__((packed));

typedef struct gdtEntry_t gdtEntry;

struct gdtPointer_t{
	uint16 limit;			// Upper 16 bits of all selector limits
	uint32 base;			// Address of the first gdt
}__attribute__((packed));

typedef struct gdtPointer_t gdtPointer;

struct idtEntry_t{
	uint16 baseLow;			// Lower 16 bits of the address to jump to on int
	uint16 sel;				// Kernel segment selector
	uint8 always0;			// Must always be zero
	uint8 flags;			// Flags
	uint16 baseHigh;		// Upper 16 bits of the address to jump to
}__attribute__((packed));

typedef struct idtEntry_t idtEntry;

struct idtPointer_t{
	uint16 limit;
	uint32 base;			// Address of the first element in the idtEntry
}__attribute__((packed));

typedef struct idtPointer_t idtPointer;

// Get access to addresses of ASM ISR handlers
extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void irq0 ();
extern void irq1 ();
extern void irq2 ();
extern void irq3 ();
extern void irq4 ();
extern void irq5 ();
extern void irq6 ();
extern void irq7 ();
extern void irq8 ();
extern void irq9 ();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

#endif