#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define CPU_INFO "/proc/cpuinfo"
#define UPTIME "/proc/uptime"
#define MEM_INFO "/proc/meminfo"
#define VERSION "/proc/version"
#define STATIC_FILES CPU_INFO, VERSION, MEM_INFO, UPTIME
#define SIZE 1024


enum static_properties{
	PROCESSOR_TYPE, KERNEL_VERSION, MEMORY, TIME_SINCE_BOOT
};


const char * static_files[] = {STATIC_FILES};


int wc = 0;


/**
 * Function to print the default statistics like
 * 	 - Processor Type
 *   - Kernel Version
 *   - The amount of memory configured into the computer
 *   - Amount of time since the system was booted
 */
void print_stats();


/**
 * Function to parse the files in /proc directory to get various information
 */
char ** parse_proc();


char ** split(char *, const char *);


int is_delim(const char, const char *);


int main(int argc, char ** argv) {
	int second_version = 0;
	if (argc == 1) {
		print_stats();	
	} else if (argc >= 3) {
		second_version = 1;	
		printf("Second version coming soon!");
	}
	return 0;
}


void print_stats() {
	char ** data = parse_proc();
}


char ** parse_proc() {
	FILE * fp;
	char * line = (char *) malloc(SIZE * sizeof(char));
	fp = fopen(VERSION, "r");
	while(fgets(line, SIZE, fp)) {
		printf("%s", line);	
		char ** spl_ans = split(line, " ");
		for (int i = 0; i < wc; ++i) {
			printf("%s\n", spl_ans[i]);	
		}	
	}
	fclose(fp);
	exit(1);
	fp = fopen(CPU_INFO, "r");
	while(fgets(line, SIZE, fp)) {
		printf("%s", line);	
		char ** spl_ans = split(line, ":");
		for (int i = 0; i < wc; ++i) {
			printf("%s\n", spl_ans[i]);	
		}	
	}
	fclose(fp);
	fp = fopen(MEM_INFO, "r");
	while(fgets(line, SIZE, fp)) {
		printf("%s", line);	
	}
	fclose(fp);
	fp = fopen(UPTIME, "r");
	while(fgets(line, SIZE, fp)) {
		printf("%s", line);	
	}
	fclose(fp);
}


char ** split(char * s, const char * delim) {
	char ** ans;
	// Count the no of words
	int word_count = 1;
	for (int i = 0; s[i] !='\0'; ++i) {
		if (is_delim(s[i], delim) && !is_delim(s[i - 1], delim)) {
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

	wc = word_count;
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
