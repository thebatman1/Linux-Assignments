#include "split.h"


struct vector split(char * s, const char * delim) {
	struct vector ans;
	// Count the no of words
	ans.length = 1;
	for (int i = 0; s[i] !='\0'; ++i) {
		if (is_delim(s[i], delim) && !is_delim(s[i - 1], delim)) {
			ans.length++;
		}
	}
	ans.strings = (char **) malloc(sizeof(char *) * ans.length);
	char * token = strtok(s, delim);
	int j = 0;

	while (token != NULL) {
		ans.strings[j] = token;
		token = strtok(NULL, delim);
		j++;
	}

	return ans;
}


int is_delim(const char c, const char * delim) {
	for (int i = 0; delim[i] != '\0'; ++i) {
		if (c == delim[i]) {
			return 1;	
		}	
	}
	return 0;
}


char * substring(const char * string, const int start, const int end) {
	int len = strlen(string);
	int n = (len < end) ? len : end;
	char * sub = (char *) malloc(sizeof(char) * (n - start + 1));
	int k = 0;
	for (int i = start; i < n; ++i) {
		sub[k++] = string[i];	
	}
	sub[k] = '\0';
	return sub;
}
