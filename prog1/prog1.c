#include <stdio.h>
typedef struct{
    int id;
    char name[50];
    float marks;
}records;

void readRecords(int n, records r[]){
    for(int i=0;i<n;i++){
        printf("Enter record %d details as Id Name Marks:\n",i+1);
        scanf("%d %s %f",&r[i].id,r[i].name,&r[i].marks);
    }
}

void storeInBinaryFile(int n, records r[]){
    FILE *fp = fopen("Records.dat","wb");
    if(fp==NULL){
        printf("Error opening file for Writing.\n");
        return;
    }
    fwrite(r,sizeof(records),n,fp);
    fclose(fp);
}

void mthRecord(int m){
    FILE *fp = fopen("Records.dat","rb");
    if(fp==NULL){
        printf("Error opening file for Writing.\n");
        return;
    }
    records r;
    fseek(fp,(m-1)*sizeof(records),SEEK_SET);

    if(fread(&r,sizeof(records),1,fp)==1){
        printf("\nRecord details:\n");
        printf("Id: %d\n",r.id);
        printf("Name: %s\n",r.name);
        printf("Marks: %.2f\n",r.marks);
    }else{
        printf("Record not found.\n");
    }
    fclose(fp);
}

void deleteRecord(int deleteId){
    FILE *fp, *temp;
    fp=fopen("records.dat","rb");
    if(fp==NULL){
        printf("Error opening file.\n");
        return;
    }
    temp=fopen("temp.dat","wb");
    if(temp==NULL){
        printf("Error opening temp file.\n");
        fclose(fp);
        return;
    }
    int flag=0;
    records r;

    while(fread(&r,sizeof(records),1,fp)==1){
        if(r.id!=deleteId){
            fwrite(&r,sizeof(records),1,temp);
        }else{
            flag=1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove("records.dat");
    rename("temp.dat","records.dat");

    if(flag)
        printf("Record deleted successfully.\n");
    else   
        printf("Record not found.\n");
}

int main(){
    int n,m,del;
    
    printf("Enter number of records: ");
    scanf("%d",&n);
    
    records r[n];
    
    readRecords(n,r);
    
    storeInBinaryFile(n,r);
    
    printf("\nEnter record to display: ");
    scanf("%d",&m);
    
    mthRecord(m); 
    
    printf("\nEnter id to delete record: ");
    scanf("%d",&del);
    
    deleteRecord(del); 
    
    return 0;
}