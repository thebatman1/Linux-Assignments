#include "proc_parser.h"


void print_static_stats() {
	FILE * fp;
	char * line = (char *) malloc(SIZE * sizeof(char));
	struct vector spl_ans;
	fp = fopen(VERSION, "r");
	fgets(line, SIZE, fp);
	spl_ans = split(line, " ");
	printf("Kernel Version: %s\n", spl_ans.strings[2]);	
	fclose(fp);
	fp = fopen(CPU_INFO, "r");
	while(fgets(line, SIZE, fp)) {
		spl_ans = split(line, ": ");
		if ((strcmp(spl_ans.strings[0], "model") == 0)) {
			if ((strcmp(substring(spl_ans.strings[1], 0, 4), "name") == 0)) {
				printf("Processor: ");
				for (int j = 2; j < 7; ++j) {
					printf("%s ", spl_ans.strings[j]);	
				}
				printf("%s", spl_ans.strings[7]);
				break;
			}
		}
	}
	fclose(fp);
	fp = fopen(MEM_INFO, "r");
	fgets(line, SIZE, fp);
	spl_ans = split(line, ": ");
	printf("Total Memory: %lf GB\n", (double)(atoi(spl_ans.strings[1]) / (1024.0 * 1024.0)));
	fclose(fp);
	fp = fopen(UPTIME, "r");
	while(fgets(line, SIZE, fp)) {
		spl_ans = split(line, ": ");
		printf("Time elapsed since last reboot: %lf hours\n", atol(spl_ans.strings[0]) / 3600.0);
	}
	fclose(fp);
}
