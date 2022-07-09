#include <stdio.h>
#include <stdint.h>

uint64_t b = 1,a = 1;
int d = 0;

int fibonacci(int c){
    d++;
    printf("%ld\n",b);
    a = b,b = c;
    if(d == 32)
        return 0;
    return  fibonacci(a+b);
}

int main(){
    fibonacci(1);
    printf("Hello world!!\n");
    return 0;
}