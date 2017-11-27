#ifndef string_h
#define string_h

#include "types.h"

uint16 strlen(char* str);							// String Length
bool streql(char* str1, char* str2);				// String Equal
char* strsub(char* str, int start, int end);	// String Sub
int strfind(char* str, char* find);				// String Find
char* strlow(char* str);						// String Lower
char* strrev(char* str);						// String Reverse
char* strupp(char* str);						// String Upper

#endif