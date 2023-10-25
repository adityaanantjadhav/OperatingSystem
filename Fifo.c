#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int mkfifo(const char *pathname, mode_t mode);

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
        
        // Get input from user
        printf("User1: ");
        fgets(arr2, 80, stdin);

        // Write input to FIFO
        write(fd, arr2, strlen(arr2) + 1);
        close(fd);

        // Open FIFO for read only
        fd = open(myfifo, O_RDONLY);

        // Read the result from the other process
        read(fd, arr1, sizeof(arr1));
        printf("User2: %s\n", arr1);

        close(fd);
    }
    return 0;
}

Read Form File
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int mkfifo(const char *pathname, mode_t mode);

int main()
{
    int fd1;
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    char str1[80], str2[80];
    while (1)
    {
        // Open FIFO for read only
        fd1 = open(myfifo, O_RDONLY);

        // Read input from the other process
        read(fd1, str1, sizeof(str1));
        printf("User1: %s\n", str1);

        close(fd1);

        // Open FIFO for write only
        fd1 = open(myfifo, O_WRONLY);
        
        // Count characters, words, and lines and write to a file
        FILE *file = fopen("output.txt", "w");
        fprintf(file, "Number of characters: %ld\n", strlen(str1) - 1);
        fprintf(file, "Number of words: %ld\n", (long)strtok(str1, " "));
        fprintf(file, "Number of lines: 1\n");
        fclose(file);

        // Write the content of the file to FIFO
        file = fopen("output.txt", "r");
        while (fgets(str2, sizeof(str2), file) != NULL)
        {
            write(fd1, str2, strlen(str2) + 1);
        }
        fclose(file);

        close(fd1);
    }
    return 0;
}

OUTPUT
