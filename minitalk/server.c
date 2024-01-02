#include <signal.h>
#include "ft_printf.h"

void handler(int signal)
{
    static int i;
    char c;
    static int sequence[8];

    if (signal == SIGUSR1)
        sequence[i++] = 1;
    else if (signal == SIGUSR2)
        sequence[i++] = 0;
    if (i == 8)
    {
        ft_printf("%u\n", sequence);
        i = 0;
    }
}
int main(void)
{
    pid_t pid;
    
    pid = getpid();
    ft_printf("pid: %d\n", pid);
    while (1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        pause();
    }
}