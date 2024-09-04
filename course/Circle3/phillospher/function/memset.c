#include <stdio.h>
#include <string.h>

int main()
{
    char ars[] = "Arsen Wenger";
    printf("%s\n", ars);
    memset(ars, 'c', 5);
    printf("%s\n", ars);
    
    return (0);
}