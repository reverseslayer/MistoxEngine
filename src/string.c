#include "include/string.h"

uint16 strlen(char* str){
	uint16 count = 0;
	while(str[count++]);
	return count;
}

bool streql(char* str1, char* str2){
	int i=0;
	bool equal = true;
	while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            equal = false;
            break;
        }
        i++;
    }
    // why did the loop exit?
    if((str1[i] == '\0' && str2[i] != '\0') || (str1[i] != '\0' && str2[i] == '\0'))
        equal = false;
    return equal;
}

char* strsub(char* str, int start, int end){
	
}

int strfind(char* str, char* find){

}

char* strlow(char* str){

}

char* strrev(char* str){

}

char* strupp(char* str){

}
