#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
    int fd;
    char fname[100];
    //char fname2[100];
    //char fext[] = ".txt";
    
    printf("Please enter the name of your file: ");
    //fgets(fname, 100, stdin);
    //fname2 = strcat(fname, fext);
    scanf("%s", fname);
    //strcat(fname, fext);
    fd = open(fname, O_CREAT | O_WRONLY | O_EXCL, 0664);

    if (fd == -1)
    {
        perror("File error: ");
        exit(1);
    } else
    {
        printf("The file has been successfully created\n");
    }
    

    close(fd);
}