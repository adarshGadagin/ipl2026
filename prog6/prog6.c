#include <stdio.h>
typedef struct{
    int h;
    int k;
    int r;
}circle;

circle input(){
    circle c;
    printf("Enter coordinates of center of circle (h,k): ");
    scanf("%d %d",&c.h,&c.k);
    printf("Enter radius of circle: ");
    scanf("%d",&c.r);

    return c;
}

void initializeBuffer(int n, char buffer[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            buffer[i][j]=' ';
        }
    }
}

void storeCircle(circle c, int n, char buffer[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x=j-c.h;
            int y=i-c.k;
            if(c.r*c.r - 1 <= x*x+y*y && x*x+y*y <= c.r*c.r + 1)
            buffer[i][j]='*';
        }
    }
}

void printCircle(int n, char buffer[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",buffer[i][j]);
        }
        printf("\n");
    }
}

int main(){
    circle c=input(c);

    int n=2*c.r+1; // diameter + center point
    char buffer[n][n]; 

    initializeBuffer(n,buffer);

    storeCircle(c,n,buffer);

    printCircle(n,buffer);

    return 0;
}