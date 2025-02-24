#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    pipe(fd);
    int childpid = fork();
    if (childpid == -1)
    {
        printf("Error\n");
    }
    if (childpid == 0)
    {
        close(fd[0]);
        char str[] = "Hello Daddy!";
        fprintf(stdout, "Child wrting to daddy\n");
        sleep(4);
        write(fd[1], str, strlen(str) + 1);
    }
    else
    {
        close(fd[1]);
        char buffer[32];
        fprintf(stdout, "Reading from child \n");
        int num_ofbyteread = read(fd[0], buffer, 32);
        fprintf(stdout, "PARENT : RECEIVED FROM CHILD %s \n", buffer);
    }
    return 0;
}