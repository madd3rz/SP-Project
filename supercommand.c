#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

    int status; // status for directory
    char cwd[1024];  //current working directory 
    DIR* dir = opendir(".");
    struct dirent* entity;

    if(argc > 1){
        
        if(strcmp(argv[1],"2") == 0 && strcmp(argv[2],"1") == 0) // Create directory
        {

            status = mkdir(argv[3], S_IRWXU | S_IRWXG | S_IXOTH);

            if(status != 0)
            {
                perror("Error creating directory");
                return 0;
            }

            else
            {
                printf("Directory has successfully been created\n");
                return 0;
            }
        } 
        else if(strcmp(argv[1],"2") == 0 && strcmp(argv[2],"2") == 0) // Remove directory
        {
            status = rmdir(argv[3]);

            if(status != 0)
            {
                perror("Error removing directory");
                return 0;
            }

            else
            {
                printf("Directory has successfully been removed\n");
                return 0;
            }
        }
        else if(strcmp(argv[1],"2") == 0 && strcmp(argv[2],"3") == 0) // display current directory
        {
            if(getcwd(cwd, sizeof(cwd)) == NULL)
			    perror("getcwd() error");
		    else
			    printf("current working directory is: %s\n\n", cwd);
                return 0;
        }
        else if(strcmp(argv[1],"2") == 0 && strcmp(argv[2],"4") == 0) // display file in current directory
        {
			entity = readdir(dir);
			printf("List of all files in current directory\n");
			while(entity != NULL)
			{
				printf("%s\n",entity->d_name);
				entity = readdir(dir);
			}
            closedir(dir);
	        return 0; 
        }

    }

    return 0;
}