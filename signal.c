#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include <stdio.h>
void catchsignal(int signal)
{
    switch (signal)
    {
    case SIGUSR1:
        printf("Sigusr1 ahve been called \n");
        break;
    case SIGUSR2:
        printf("sigusr2 have been called");
        break;
    default:
        break;
    }
}
int main()
{
    printf("the process id is %d  hello \n", getpid());
    signal(SIGUSR1, catchsignal);

    while (1)
        ;
    return 0;
}