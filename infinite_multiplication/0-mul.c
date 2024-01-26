#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int is_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int num1, num2, result;

    if (argc != 3)
    {
        write(1, "Error\n", 6);
        exit(98);
    }
    if (!is_number(argv[1]) || !is_number(argv[2]))
    {
        write(1, "Error\n", 6);
        exit(98);
    }
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    if (num1 < 0 || num2 < 0)
    {
        write(1, "Error\n", 6);
        exit(98);
    }
    result = num1 * num2;
    printf("%d\n", result);
    return (0);
}
