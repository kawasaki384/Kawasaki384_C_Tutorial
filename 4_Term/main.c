#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Terminal[25][25];

typedef struct apps {
    int (*apps[100])(void);
    char appsName[100][24];
} Term_Apps;

char* args[1024];
char buf[1024];

Term_Apps Apps;
int count = 0;

void ClearBuf()
{
    for (int i = 0; i < 1024; i++)
        buf[i] = '\0';
    for (int i = 0; i < 1024; i++)
        args[i] = "\0";
}
void SetApp(int (*p)(void), char Name[24])
{
    Apps.apps[count] = p;
    for (int i = 0; i < 24; i++)
        Apps.appsName[count][i] = Name[i];
    count++;
}

int add(void)
{
    const char* a = args[0];
    const char* b = args[1];
    if (!strcmp(a, "null") || !strcmp(b, "null")) {
        printf("args_error\n");
        return 1;
    }

    if ((strlen(a) > 12 || strlen(b) > 12)) {
        printf("Number is to big \n");
        return 2;
    }

    printf("a,b:%d \n", atoi(a) + atoi(b));
    return 0;
}

int Exit()
{
    exit(0);
}

int main()
{
    SetApp(add, "add");
    SetApp(Exit, "exit");
    while (1) {
        ClearBuf();
        for (int i = 0; i < 1024; i++) {
            buf[i] = fgetc(stdin);
            if (buf[i] == '\n') {
                buf[i] = '\0';
                break;
            }
        }

        char* command = strtok(buf, " ");

        if (command == NULL) {
            printf("Command is NULL \n");
            continue;
        }

        for (int i = 0; i < 1024; i++) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL) {
                args[i] = "null";
            }
        }

        {
            bool A = 0;
            for (int i = 0; i < 100; i++) {
                if (!strcmp(Apps.appsName[i], command)) {
                    A = true;
                    int Return = Apps.apps[i]();
                    printf("%s:return value:%d\n",
                        Apps.appsName[i], Return);
                }
            }
            if (A == false)
                printf("%s: command not found \n", command);
        }
    }
}