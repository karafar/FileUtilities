#ifndef __FILE_UTILS_H
#define __FILE_UTILS_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

// Returns file size on success, -1 on error
int read_file(char* filename, char **buffer);

// Returns 0 on success, -1 on error
int write_file(char* filename, char *buffer, int size);

#endif 
