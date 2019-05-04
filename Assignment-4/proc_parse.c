#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "proc_parser.h"

int main(int argc, char ** argv) {
	int second_version = 0;
	if (argc == 1) {
		print_static_stats();	
	} else if (argc >= 3) {
		second_version = 1;	
		exit(0);
	}
	return 0;
}


