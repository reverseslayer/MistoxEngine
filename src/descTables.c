#include "include/descTables.h"

// ASM functions
extern void gdt_flush(uint32);
extern void idt_flush(uint32);

// Internal function protos
static void initGdt();
static void initIdt();
static void gdtSetGate(int32, uint32, uint32, uint8, uint8);
static void idtSetGate(uint8, uint32, uint16, uint8);

gdtEntry gdtEntries[5];
gdtPointer gdtPtr;
idtEntry idtEntries[256];
idtPointer idtPtr;

//extern the isr handler so we can null them on startup
extern isr interruptHandlers[];

// zero all isr's and init the gdt and idt
void initDescTbls(){
	initGdt();											// init global desc tbl
	initIdt();											// init int desc tbl
	memSet(&interruptHandlers, 0, sizeof(isr)*256);		// null int handlers
}

static void initGdt(){
    gdtPtr.limit = (sizeof(gdtEntry) * 5) - 1;
    gdtPtr.base  = (uint32)&gdtEntries;

    gdtSetGate(0, 0, 0, 0, 0);                // Null segment
    gdtSetGate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdtSetGate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdtSetGate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdtSetGate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    gdt_flush((uint32)&gdtPtr);
}

static void gdtSetGate(int32 num, uint32 base, uint32 limit, uint8 access, uint8 gran){
    gdtEntries[num].baseLow    = (base & 0xFFFF);
    gdtEntries[num].baseMiddle = (base >> 16) & 0xFF;
    gdtEntries[num].baseHigh   = (base >> 24) & 0xFF;

    gdtEntries[num].limitLow   = (limit & 0xFFFF);
    gdtEntries[num].granularity = (limit >> 16) & 0x0F;
    
    gdtEntries[num].granularity |= gran & 0xF0;
    gdtEntries[num].flags      = access;
}

static void initIdt()
{
    idtPtr.limit = sizeof(idtEntry) * 256 -1;
    idtPtr.base  = (uint32)&idtEntries;

    memSet(&idtEntries, 0, sizeof(idtEntry)*256);

    // Remap the irq table.
    outportb(0x20, 0x11);
    outportb(0xA0, 0x11);
    outportb(0x21, 0x20);
    outportb(0xA1, 0x28);
    outportb(0x21, 0x04);
    outportb(0xA1, 0x02);
    outportb(0x21, 0x01);
    outportb(0xA1, 0x01);
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0);

    idtSetGate( 0, (uint32)isr0 , 0x08, 0x8E);
    idtSetGate( 1, (uint32)isr1 , 0x08, 0x8E);
    idtSetGate( 2, (uint32)isr2 , 0x08, 0x8E);
    idtSetGate( 3, (uint32)isr3 , 0x08, 0x8E);
    idtSetGate( 4, (uint32)isr4 , 0x08, 0x8E);
    idtSetGate( 5, (uint32)isr5 , 0x08, 0x8E);
    idtSetGate( 6, (uint32)isr6 , 0x08, 0x8E);
    idtSetGate( 7, (uint32)isr7 , 0x08, 0x8E);
    idtSetGate( 8, (uint32)isr8 , 0x08, 0x8E);
    idtSetGate( 9, (uint32)isr9 , 0x08, 0x8E);
    idtSetGate(10, (uint32)isr10, 0x08, 0x8E);
    idtSetGate(11, (uint32)isr11, 0x08, 0x8E);
    idtSetGate(12, (uint32)isr12, 0x08, 0x8E);
    idtSetGate(13, (uint32)isr13, 0x08, 0x8E);
    idtSetGate(14, (uint32)isr14, 0x08, 0x8E);
    idtSetGate(15, (uint32)isr15, 0x08, 0x8E);
    idtSetGate(16, (uint32)isr16, 0x08, 0x8E);
    idtSetGate(17, (uint32)isr17, 0x08, 0x8E);
    idtSetGate(18, (uint32)isr18, 0x08, 0x8E);
    idtSetGate(19, (uint32)isr19, 0x08, 0x8E);
    idtSetGate(20, (uint32)isr20, 0x08, 0x8E);
    idtSetGate(21, (uint32)isr21, 0x08, 0x8E);
    idtSetGate(22, (uint32)isr22, 0x08, 0x8E);
    idtSetGate(23, (uint32)isr23, 0x08, 0x8E);
    idtSetGate(24, (uint32)isr24, 0x08, 0x8E);
    idtSetGate(25, (uint32)isr25, 0x08, 0x8E);
    idtSetGate(26, (uint32)isr26, 0x08, 0x8E);
    idtSetGate(27, (uint32)isr27, 0x08, 0x8E);
    idtSetGate(28, (uint32)isr28, 0x08, 0x8E);
    idtSetGate(29, (uint32)isr29, 0x08, 0x8E);
    idtSetGate(30, (uint32)isr30, 0x08, 0x8E);
    idtSetGate(31, (uint32)isr31, 0x08, 0x8E);
    idtSetGate(32, (uint32)irq0, 0x08, 0x8E);
    idtSetGate(33, (uint32)irq1, 0x08, 0x8E);
    idtSetGate(34, (uint32)irq2, 0x08, 0x8E);
    idtSetGate(35, (uint32)irq3, 0x08, 0x8E);
    idtSetGate(36, (uint32)irq4, 0x08, 0x8E);
    idtSetGate(37, (uint32)irq5, 0x08, 0x8E);
    idtSetGate(38, (uint32)irq6, 0x08, 0x8E);
    idtSetGate(39, (uint32)irq7, 0x08, 0x8E);
    idtSetGate(40, (uint32)irq8, 0x08, 0x8E);
    idtSetGate(41, (uint32)irq9, 0x08, 0x8E);
    idtSetGate(42, (uint32)irq10, 0x08, 0x8E);
    idtSetGate(43, (uint32)irq11, 0x08, 0x8E);
    idtSetGate(44, (uint32)irq12, 0x08, 0x8E);
    idtSetGate(45, (uint32)irq13, 0x08, 0x8E);
    idtSetGate(46, (uint32)irq14, 0x08, 0x8E);
    idtSetGate(47, (uint32)irq15, 0x08, 0x8E);

    idt_flush((uint32)&idtPtr);
}

static void idtSetGate(uint8 num, uint32 base, uint16 sel, uint8 flags)
{
    idtEntries[num].baseLow = base & 0xFFFF;
    idtEntries[num].baseHigh = (base >> 16) & 0xFFFF;

    idtEntries[num].sel    = sel;
    idtEntries[num].always0 = 0;
    // We must uncomment the OR below when we get to using user-mode.
    // It sets the interrupt gate's privilege level to 3.
    idtEntries[num].flags   = flags /* | 0x60 */;
}
