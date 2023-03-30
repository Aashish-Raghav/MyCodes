#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int id;
    int class;
    int name[50];
} stu;                      //Not Got;

int main() {
    int ch;
    char choice;
do {
printf("1.Add\t2.DispAll\t3.Search\t4.Update\t5.Delete\t6.Exit : "); scanf("%d",&ch);
if ( ch == 1) {
    printf("Enter Student Id : "); scanf("%d",&stu.id);
    printf("Enter Student class : "); scanf("%d",&stu.class);
    printf("Enter Student name : "); fflush(stdin); scanf("%s",stu.name);
    FILE * fp = fopen("student.dat","ab");
    if (fp == NULL) {
        printf("Memory Failure!");
        exit(0);
        fclose(fp);
    }else {
        fwrite(&stu,sizeof(stu),1,fp);          
        fclose(fp);
        printf("\nData Written Successfully\n\n"); 
    }    
}

else if (ch == 2) {
    FILE * fp = fopen("student.dat","rb");
    if (fp == NULL) {
        printf("Cannot open file!\n");
        exit(0);
        fclose(fp);
    } else {
        printf("Id\tClass\tName\n");
        printf("------------------------------\n");
        while (fread(&stu,sizeof(stu),1,fp)) {
        printf("%d\t%d\t%s\n",stu.id,stu.class,stu.name);
        }
        printf("------------------------------\n\n");
    }
    fclose(fp);
}

else if (ch == 3) {
    int id_req,flag=0;
    printf("Enter Id : "); fflush(stdin); scanf("%d",&id_req);
    FILE * fp = fopen("student.dat","rb");
    if (fp == NULL) {
        printf("Cannot open File!");
        exit(0);
        fclose(fp);
    } else {
        while (fread(&stu,sizeof(stu),1,fp)) {
         if (stu.id == id_req){
         printf("Id\tClass\tName\n");
         printf("------------------------------\n");
         printf("%d\t%d\t%s\n",stu.id,stu.class,stu.name);
         printf("------------------------------\n\n");
         flag=1;
         break;
         }
        }
    fclose(fp);
    }
    if (flag==0) printf("No Record Found!\n\n");
}

else if (ch == 4) {
    int id_req,flag=0;
    printf("Enter Student Id :");fflush(stdin); scanf("%d",&id_req);
    FILE * fp = fopen("student.dat","rb+");
    if (fp == NULL ) {
        printf("Cannot open File!");
        exit(0);
        fclose(fp);
    } else {
        while (fread(&stu,sizeof(stu),1,fp)) {
         if (stu.id == id_req) {
         printf("Enter New Class : "); fflush(stdin); scanf("%d",&stu.class);
         printf("Enter New Name : "); fflush(stdin); scanf("%s",stu.name);
         fseek(fp,-sizeof(stu),1);
         fwrite(&stu,sizeof(stu),1,fp);
         printf("Data Updated Successfully\n\n");
         break;
         flag=1;
         }
        }
        fclose(fp);
    }
    if (flag==0) printf("NO Record Found!Id cannot be updated.\n\n");
}
else if (ch == 5){
    int id_req,flag=0;
    printf("Enter student id : "); scanf("%d",&id_req);
    FILE * fp,*tfp;
    fp = fopen("student.dat","rb");
    tfp = fopen("student1.dat","wb");
    if (fp == NULL && tfp == NULL ) {
        printf("Cannot open file!");
        exit(0);
        fclose(fp);
        fclose(tfp);
    } else {
        while (fread(&stu,sizeof(stu),1,fp)) {
         if (id_req != stu.id) {
         fwrite(&stu,sizeof(stu),1,tfp);
         } else flag=1;
        }
        fclose(fp);
        fclose(tfp);
        remove("student.dat");
        rename("student1.dat","student.dat");

        if (flag == 1) printf("Deleted successfully\n\n");
        else printf("Record Not found!\n\n");
    }

} else if (ch == 6) break;

else printf("Invlaid Input\n\n");
printf("Do you want to continue(y/n) :"); fflush(stdin); scanf("%c",&choice); printf("\n");
    } while (choice == 'y' || choice == 'Y');
}