#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void print(const char *text)
{
    printf("hello form %s\n", text);
}
int main()
{
    // create child
    pid_t pid = fork();
    if (pid == 0)
    {
        // we are in child
        // create a grand child
        pid_t pid = fork();
        if (pid == 0)
        {
            // we are in the grand child
            printf("grand child");
        }
        else
        {
            print("child");
        }
    }
    else
    {
        print("parent");
    }
    return 0;
}