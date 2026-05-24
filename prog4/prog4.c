#include <stdio.h>
struct bitField{
    unsigned int firstbit:1;
    unsigned int secondbit:2;

    unsigned :2;      // skipping bits
    unsigned :0;      // forcing c in new allocation unit
    unsigned int test:3;
};

int main(){
    struct bitField a;
    a.firstbit=1;
    printf("%u\n",a.firstbit);
    
    int temp;

    printf("Enter 2-bit integer (0-3): ");
    scanf("%d",&temp);

    a.secondbit=temp;
    printf("%u\n",a.secondbit);
    
    printf("size of bitField: %zu\n",sizeof(struct bitField));

    return 0;
}