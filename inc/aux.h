#ifndef  __AUXH__
#define __AUXH__

#ifdef __linux__
/**
 * @brief Function that converts all characters in a string to lowercase
 * 
 * @param str string to convert
 * @return char* string converted
 */
char *strlwr( char *str );
#endif

/**
 * @brief Function that allocates dinamically a space for a string given
 * 
 * @param str string to be stored
 * @return char* address of the dinamically allocated string
 */
char *stralloc( char *str );

#endif