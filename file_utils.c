#include "file_utils.h"

int read_file(char* filename, char** buffer)
{
	// Open file
	FILE* file = NULL;
	file = fopen(filename, "r");
	if( file == NULL )
	{
		fprintf( stderr, "File, %s, could not be opened for \
		reading", filename );
		return -1;
	}

	// Find size of the file, allocate memory
	struct stat st;
	stat( filename, &st );
	int size = st.st_size;
	*buffer = malloc( size * sizeof(char) );
	
	// Read the file
	int c;
	for (int i = 0; i < size; i++)
	{
		c = fgetc(file);
		**buffer = (char) c;
		*buffer += 1;
	}

	// Close file. Go to first address of array.
	fclose(file);
	*buffer -= (size);

	return size;

}


int write_file(char* filename, char* buffer, int size)
{
	FILE* file = NULL;
	file = fopen(filename, "w");
	if( file == NULL )
	{
		fprintf(stderr, "File, %s, could not be opened for \
		writing", filename);
		return -1;
	}

	for( int i = 0; i < size; i++ )
	{
		fputc( *buffer, file );
		buffer += 1;
	}

	// Return to first address
	buffer -= (size);
	
	fclose(file);
	
	return 0;
}

