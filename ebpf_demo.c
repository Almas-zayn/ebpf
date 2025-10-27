// file_ops_demo.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "demo.txt"

int main()
{

    int fd = open(FILENAME, O_CREAT | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    write(fd, "Testing the code with ebpf\n", 27);
    close(fd);

    printf("process id: %d\n", getpid());

    for (int i = 0; i < 10; i++)
    {
        fd = open(FILENAME, O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            return 1;
        }

        char buffer[128];
        read(fd, buffer, sizeof(buffer));
        close(fd);

        sleep(10);
    }

    printf("Finished file operations demo.\n");
    return 0;
}