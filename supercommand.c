#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int getFileLength(int fd);

int main(int argc, char *argv[])
{
    int fd;
    char fname[100];
    int status; // status for directory
    char cwd[1024];  //current working directory 
    DIR* dir = opendir(".");
    struct dirent* entity;

    if (argc > 1)
    {
        if (strcmp(argv[1], "1") == 0 && strcmp(argv[2], "1") == 0) // Create new file
        {
            fd = open(argv[3], O_CREAT | O_RDWR | O_EXCL, 0700);

            if (fd == -1)
            {
                perror("File error: ");
                exit(1);
            }
            else
            {
                printf("The file has been successfully created\n");
            }
            close(fd);
        }

        if (strcmp(argv[1], "1") == 0 && strcmp(argv[2], "2") == 0) // change file permission
        {
            fd = open(argv[3], O_RDWR);
            unsigned long mode = strtoul(argv[4], NULL, 8);
            fchmod(fd, mode);

            if (fd == -1)
            {
                perror("File error: ");
                exit(1);
            }
            else
            {
                printf("The file has been successfully edited\n");
            }
            close(fd);
        }

        if (strcmp(argv[1], "1") == 0 && strcmp(argv[2], "3") == 0) // read from a given file and print to the standard output
        {
            int fd = open(argv[3],O_RDONLY); // open the source file with O_RDONLY permission 
            if(fd < 0){
                perror("Error open file!");
                exit(1); 
	        }

            int fileLength = getFileLength(fd);
            char *buf[fileLength];

            read(fd, buf, fileLength);  // read content from source file fd
            write(1, buf, fileLength);  // write to stdout
            close(fd);                  // close fd
        }

        if (strcmp(argv[1], "1") == 0 && strcmp(argv[2], "4") == 0) //remove or delete a file given the file name
        {
            char *filepath = argv[3];
            int status;

            status = unlink(filepath);

            if (status <0 )
            {
                perror("Error removing file!");
            }

            fprintf(stdout, "%s successfully removed!\n", filepath);
        }

        if (strcmp(argv[1], "2") == 0 && strcmp(argv[2], "1") == 0) // Create directory
        {

            status = mkdir(argv[3], S_IRWXU | S_IRWXG | S_IXOTH);

            if (status != 0)
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

        if (strcmp(argv[1], "2") == 0 && strcmp(argv[2], "2") == 0) // Remove directory
        {
            status = rmdir(argv[3]);

            if (status != 0)
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
        
        if(strcmp(argv[1],"2") == 0 && strcmp(argv[2],"4") == 0) // display file in current directory
        {
            DIR* dir = opendir(".");
            struct dirent* entity;

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
        
        if (strcmp(argv[1], "3") == 0) // execute other linux command
        {
            pid_t p;
            p = fork();

            if (p == -1)
            {
                printf("Error");
            }
            if (p == 0)
            {
                execlp(argv[2], argv[2], argv[3], (char *)NULL);
            }
        }
    }

    return 0;
}

int getFileLength(int fd){
    // This function returns the length of the file in bytes
    int fileLength = lseek( fd, 0, SEEK_END );  // get file length using lseek()
    if ( fileLength < 0 ){
        exit(1);
    }
    lseek(fd, 0, SEEK_SET); // return to beginning position of file after seek to EOF above

    return fileLength;
}