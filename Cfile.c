#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int fd;
    char fname[100];

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

        if (strcmp(argv[1], "1") == 0 && strcmp(argv[2], "2") == 0)
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
    }

}