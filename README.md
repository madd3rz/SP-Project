## The new tool/command should be able to do this:
* A menu system for selecting which operation to be conducted. Options are:
    * 1 for file operations
    * 2 for directory operations
    * 3 for executing other command (using fork() and exec system call)
> (this menu and submenu can be implemented using the standard I/O, using stdio.h library)  

1. For (1) file operations:
* Create/Open a new file and have the ability to specify the filename and the path.  
* Change the permission of a file based on user input.  
* read from a given file and print to the standard output.  
* Remove or delete a file given the file name.  

2. For (2) directory operations:
* Create a directory (mkdir) using a given name and specified path (if any).
* Remove (delete) a directory using a given name and specified path (if any).
* Get the current working directory.
* List current directory (and files). Able to list file(s) in the current directory (use readdir)

3. For (3) options, the operations are still yet to be implemented.
