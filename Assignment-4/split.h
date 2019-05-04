#ifndef SPLIT_H
#define SPLIT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * A structure to hold the return value from split function
 * @member length : Length of the string array after the split
 * @member strings: The string array after the split
 */
struct vector {
	int length;
	char ** strings;
};


/**
 * A function to split a string based on a set of given delimiters
 * @param string : The string to be split based on the delimiters
 * @param delim  : A string consisting of all the delimiters based on which
 * 					the string will be split
 * @returns      : A vector of strings and the length of the string array
 */
struct vector split(char *, const char *);


/**
 * A helper method to check if the current character is the delimiter
 * @param c 	: The current character
 * @param delim : A null terminated string containing all the delimiters
 * @returns     : 1 if the character is a delimiter, else 0
 */
int is_delim(const char, const char *);


/**
 * A function to return the substring of a string
 * @param string : The string whose substring needs to be returned
 * @param start  : The starting index
 * @param end    : The ending index
 * @returns      : The substring
 */
char * substring(const char *, const int, const int);

#endif
