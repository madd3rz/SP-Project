#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int status; // status for directory

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

    }

    return 0;
}