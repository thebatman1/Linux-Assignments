#ifndef PROC_PARSER_H
#define PROC_PARSER_H
#define CPU_INFO "/proc/cpuinfo"
#define UPTIME "/proc/uptime"
#define MEM_INFO "/proc/meminfo"
#define VERSION "/proc/version"
#define SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include "split.h"

/**
 * Function to print the default statistics like
 * 	 - Processor Type
 *   - Kernel Version
 *   - The amount of memory configured into the computer
 *   - Amount of time since the system was booted
 */
void print_static_stats();


#endif
