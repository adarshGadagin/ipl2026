// Write a function to print the bits in an integer.
// Write a function to count no of 1 bits in an integer.

#include <stdio.h>
void intToBin(int n){
    int binary[32];
    if(n==0){
        printf("Bits: 0");
        return;
    }
    int i=0;
    while(n>0){
        binary[i]=n%2;
        n=n/2;
        i++;
    }
    printf("Bits: ");
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);
    }
}

void countOneBits(int n){
    int i=0;
    while(n>0){
        n = n & (n-1);
        i++;
    }
    printf("\n1 bits: %d\n",i);
}

int main(){
    int n;
    printf("Enter an integer: ");
    scanf("%d",&n);
    intToBin(n);
    countOneBits(n);
    return 0;
}
