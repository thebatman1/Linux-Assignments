#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(void) {
	printf("Welcome to my shell!\n");
	printf("$ ");
	pid_t return_val;
	char * s = (char *) malloc(1024 * sizeof(char));
	memset(s, '\0', sizeof(s));
	const char * EXIT_STRING = "exit";
	int status;
	while (1) {
		scanf("%[^\n]s", s);	
		if (strcmp(s, EXIT_STRING) == 0) {
			exit(0);	
		}
		return_val = fork();
		if (return_val > 0) {
			wait(&status);	
		} else if (return_val == 0) {
			execlp(s, s, NULL);	
		} else {
			fprintf(stderr, "Command could not be run!\n");	
		}
		// To clear the buffer
		while ((getchar()) != '\n');
		printf("$ ");
	}
	
	return 0;
}
