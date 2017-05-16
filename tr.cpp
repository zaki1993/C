#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv)
{

	if(argc != 3)
	{
		return 1;
	}

	FILE* file_one = fopen(argv[1], "r");
	FILE* file_two = fopen(argv[2], "r");

	if(file_one && file_two)
	{
		// files exist and can be open
		char file_one_content[BUFFER_SIZE];
		char file_two_content[BUFFER_SIZE];

		// read file content
		fscanf(file_one, "%s", (char*) file_one_content);
		fscanf(file_two, "%s", (char*) file_two_content);

		printf("Executing: tr %s %s\n", file_one_content, file_two_content);
		execlp("tr", "tr", file_one_content, file_two_content);
	}
	else
	{
		// files does not exist
		printf("Executing: tr %s %s\n", argv[1], argv[2]);
		execlp("tr", "tr", argv[1], argv[2]);
	}
	fclose(file_one);
	fclose(file_two);
	return 0;
}