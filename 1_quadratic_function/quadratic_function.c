#include <math.h>
#include <stdio.h>

int main()
{
    printf("Puadratic_Function \n");
    printf("X:Space 2 = Y:Space 1 \n");
    for(int i = 0; i < 44;i++)
        putchar('~');
    putchar('\n');

    for (int i = 0; i < 40; i++) {
        putchar('~');
        for (int j = -20; j < 21; j++) {
            //                     ↓これが傾き X < 0 の場合
            if ((int)(sqrt(19 - i)*2) == -j-1 && j < 0) {
                putchar('*');
            }
            else if (i == 19 && j == 0)
                putchar('+');
            else if (i == 19)
                putchar('-');
            else if (j == 0)
                putchar('|');
            else
                putchar(' ');
            //                     ↓これが傾き X >= 0 の場合
            if ((int)(sqrt(19 - i)*2) == j && j > -1) {
                putchar('*');
            }
        }
        if(i >= 20)
            printf(" ~");
        else 
            putchar('~');
        putchar('\n');
    }

    for(int i = 0; i < 44;i++)
        putchar('~');

    printf("\n");

    return 0;
}