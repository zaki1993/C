#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		return 1;
	}

	bool attribute = strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-l") || strcmp(argv[1], "-w");
	
	for(int i = 2; i < argc; i++)
	{
		FILE* crr_file = fopen(argv[i], "r");
		if(crr_file)
		{
			// the file exist
			char buffer[BUFFER_SIZE];
			if(!fork())
			{
				if(attribute)
				{
					execlp("wc", "wc", argv[1], argv[i]);
				}
				else
				{
					execlp("wc", "wc", argv[i]);
				}
			}
			else
			{
				int status;
				wait(&status);
			}
		}
		fclose(crr_file);
	}
	return 0;
}