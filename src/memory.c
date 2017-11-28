#include "include/memory.h"

// Copy len bytes from src to dest
void* memCopy(void* dest, const void* src, uint32 len){
    string sp = (string) src;
    string dp = (string) dest;
    for(; len != 0; len--)
        *dp++ = *sp++;
    return dest;
}

// Write len copies of val into dest.
void* memSet(void* dest, char val, uint32 len){
    string temp = (string) dest;
    for (; len != 0; len--)
        *temp++ = val;
    return dest;
}

// Like memset but with uint16
uint16* memSetW(uint16* dest, uint16 val, uint32 count){
    uint16* temp = (uint16 *)dest;
    for( ; count != 0; count--)
        *temp++ = val;
    return dest;
}
