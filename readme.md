Assignment for CIS 343 @ GVSU

Only runs on linux based operating systems.

`file_utils` contains two functions. One for reading a file and the other for
writing to a file. 

`reverse.c` contains an optional main file.

`test.o` is a test file provided by the instructor.

`test.txt` is a file to be read. `t.txt` is the file being written to.

The file can be compiled with `clang file_utils.c reverse.c -o reverse`, and then ran with
`./reverse file_to_be_read file_to_be_written'.

For testing, compile with the command `clang test.o file_utils.c -o reverse`.
Then run with `./reverse file_to_be_read file_to_be_written`.



