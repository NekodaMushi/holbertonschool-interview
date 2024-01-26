#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int is_number(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


char *multiply_strings(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_res = len1 + len2;
    int *res = calloc(len_res, sizeof(int));


    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j] += sum / 10;
            res[i + j + 1] = sum % 10;
        }
    }


    char *result = malloc((len_res + 1) * sizeof(char));
    int k = 0;
    int i = 0;
    while (i < len_res && res[i] == 0) i++;
    while (i < len_res) {
        result[k++] = res[i++] + '0';
    }
    result[k] = '\0';

    free(res);
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2])) {
        write(1, "Error\n", 6);
        return 98;
    }

    char *num1 = argv[1];
    char *num2 = argv[2];


    char *result = multiply_strings(num1, num2);
    

    printf("%s\n", result);


    free(result);

    return 0;
}
