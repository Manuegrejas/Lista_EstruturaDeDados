#include <stdio.h>

int fib(int n){
    if(n == 0 || n ==1){
            return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    printf("fibonacci\n");

    printf("%d ", fib(5));
    printf("\n");
}