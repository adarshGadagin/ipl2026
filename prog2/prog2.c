#include <stdio.h>
typedef struct{
    int id;
    char name[50];
    float salary;
}Employee;

void readDetails(int n, Employee e[]){
    printf("Enter details as ID Name Salary:\n");
    for(int i=0;i<n;i++){
        scanf("%d %s %f",&e[i].id,e[i].name,&e[i].salary);
    }
}

void storeInTAscii(int n, Employee e[]){
    FILE *fp=fopen("employee.txt","w");
    if(fp==NULL){
        printf("Error opening file.\n");
        return;
    }
    for(int i=0;i<n;i++){
        fprintf(fp,"%d %s %.2f\n",e[i].id,e[i].name,e[i].salary);
    }
    fclose(fp);
}

void arrOfSeekPos(int *cnt,long pos[]){
    FILE *fp=fopen("employee.txt","r");
    if(fp==NULL){
        printf("Error opening file.\n");
        return;
    }
    Employee e;
    fseek(fp,0,SEEK_SET);

    while(1){
        pos[*cnt]=ftell(fp);
        if(fscanf(fp,"%d %s %f",&e.id,e.name,&e.salary)!=3)
            break;
        (*cnt)++;
    } 
    fclose(fp);  
}

void recByPos(int m, long pos[]){
    FILE *fp=fopen("employee.txt","r");
    if(fp==NULL){
        printf("Error opening file.\n");
        return;
    }

    Employee e;
    fseek(fp,pos[m-1],SEEK_SET);

    if(fscanf(fp,"%d %s %f",&e.id,e.name,&e.salary)==3){
        printf("Id: %d\n",e.id);
        printf("Name: %s\n",e.name);
        printf("Salary: %.2f\n",e.salary);
    }else{
        printf("Record not found.\n");
    }
    fclose(fp);
}


int main(){
    int n,m;
    printf("Enter number of records: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input.\n");
        return 0;
    }
    Employee e[n];
    long pos[n];
    int cnt=0;
    readDetails(n,e);
    storeInTAscii(n,e);
    arrOfSeekPos(&cnt,pos);
    printf("Enter record number: ");
    scanf("%d",&m);
    if(m<=0){
        printf("Invalid input.\n");
        return 0;
    }
    recByPos(m,pos);

    return 0;
}