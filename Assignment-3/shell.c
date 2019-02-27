#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define EXIT_STRING "exit"
#define CHANGE_DIR "cd"
#define ECHO "echo"

/**
 * Function to handle shell builins.
 * As of now, we are handling only three builtins: cd, exit, and echo(partially)
 * @param line: A string containing one or more space separated words that 
 * 				comprise of the command and its arguments
 */
void handle_builtins(char **);


/**
 * Function to split a string based on a given delimiter
 * @param line: A string containing one or more space separated words that
 * 				comprise of the command and its arguments
 * @returns   : An array of strings where the first string is the command and the rest are the arguments
 */
char ** split(char *, const char *);


int argc = 0;

int main(void) {
	printf("Welcome to my shell!\n");
	printf("As of now, only three builtins have been considered:\n");
	printf("cd, exit and echo(partially).\nSo using other builtins may have ");
	printf("undefined behaviour!\n");
	printf("You are free to use external shell commands like ls, cat, etc.\n");
	printf("$ ");
	pid_t return_val;
	char * s = (char *) malloc(1024 * sizeof(char));
	memset(s, '\0', sizeof(s));
	int status;
	while (1) {
		scanf("%[^\n]s", s);	
		char ** args = split(s, " ");
		if (strcmp(s, EXIT_STRING) == 0 || 
				strcmp(s, CHANGE_DIR) == 0 ||
				strcmp(s, ECHO) == 0) {
			handle_builtins(args);
		} else {
			int err_val;
			return_val = fork();
			if (return_val > 0) {
				wait(&status);	
			} else if (return_val == 0) {
				err_val = execvp(args[0], args);	
				if (err_val != 0) {
					printf("No such command as %s. Maybe check the man page!\n", args[0]);
					return err_val;	
				}
			} else {
				fprintf(stderr, "Command could not be run!\n");	
			}
		}
		// To clear the buffer
		while ((getchar()) != '\n');
		printf("$ ");
	}
	
	return 0;
}


char ** split(char * s, const char * delim) {
	char ** ans;
	// Count the no of words
	int word_count = 1;
	for (int i = 0; s[i] !='\0'; ++i) {
		if (s[i] == delim[0]) {
			word_count++;
		}
	}
	ans = (char **) malloc(sizeof(char *) * word_count);
	char * token = strtok(s, delim);
	int j = 0;

	while (token != NULL) {
		ans[j] = token;
		token = strtok(NULL, delim);
		j++;
	}

	argc = word_count;
	return ans;
}


void handle_builtins(char ** argv) {
	if (strcmp(argv[0], EXIT_STRING) == 0) {
		exit(0);	
	} else if (strcmp(argv[0], CHANGE_DIR) == 0) {
		if (argc == 1) {
			chdir("/home/mrinmay/");	
		} else if (argc > 1) {
			chdir(argv[1]);	
		}
	} else if (strcmp(argv[0], ECHO) == 0) {
		if (argc == 1) {
			printf("\n");				
		} else {
			for (int i = 1; i < argc; ++i) {
				printf("%s ", argv[i]);	
			}
			printf("\n");
		}
	}	
}
