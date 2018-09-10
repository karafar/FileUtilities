#include <stdio.h>
#include "file_utils.h"

int main(int argc, char** argv)
{
	// Handles incorrect number of arguments
	if (argc > 3)
	{
		fprintf(stderr, "Too many arguments.\n \
		Expected file_to_read file_to_write\n");
		return -1;
	}

	if (argc < 3)
	{
		fprintf(stderr, "Too few arguments.\n \
		Expected file_to_read file_to_write\n");
		return -1;
	}
	
	// Sets up vars to be used with file_utils
	char* file_to_read = argv[1];
	char* file_to_write = argv[2];
	char* buffer;
	int size = 0;

	// Read file.
	size = read_file(file_to_read, &buffer);
	
	// Reverse the buffer
	char* reversed = malloc( size * sizeof(char) );
	reversed += (size-1);
	for( int i = 0; i < size; i++ )	
	{
		*reversed = *buffer;
		reversed -= 1;
		buffer += 1;
	}

	// Go to beginning of each char*.
	// The plus one makes up for the final round of the loop.
	reversed += 1;
	buffer -= (size);

	write_file(file_to_write, reversed, size);

	free(buffer);
	free(reversed);
	
	return 0;
}
