#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_NUMBER_OF_LINES 100
#define DEFAULT_LINE_LENGTH 100

void generate_random_line(char *, int);
char generate_random_char();

int main(int argc, char ** argv)
{
        int i;
        int number_of_lines = argc >= 3 ? atoi(argv[2]) : DEFAULT_NUMBER_OF_LINES;
        int line_length = argc >= 4 ? atoi(argv[3]) : DEFAULT_LINE_LENGTH;
        char a[line_length];
        FILE * file_to_write = fopen(argv[1], "w");
        for (i = 0; i < number_of_lines; i++) {
                generate_random_line(a, line_length);
                fprintf(file_to_write, "%s\n", a);
        }
}

void generate_random_line(char * str, int line_length)
{
        int i, max;
        max = line_length - 1;
        for (i = 0; i < max; i++)
                str[i] = generate_random_char();
        str[max] = '\0';
}

char generate_random_char()
{
        if (random() % 2)
                return 'A' + (random() % 26);
        else
                return 'a' + (random() % 26);
}
