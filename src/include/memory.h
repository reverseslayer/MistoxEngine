#ifndef memory_h
#define memory_h

#include "types.h"

void* memCopy(void*, const void*, uint32);
void* memSet(void*, char, uint32);
uint16* memSetW(uint16*, uint16, uint32);

#endif