#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#ifdef __linux__

char *strlwr( char *str ) {
    unsigned char *p = (unsigned char *)str;

    while (*p) {
        *p = tolower(*p);
        p++;
    }

    return str;
}

#endif //__linux__

char *stralloc( char *str ){
    char *new_str = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(new_str, str);
    return new_str;
}