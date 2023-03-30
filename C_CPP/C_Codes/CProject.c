#include<stdio.h>
#include<stdlib.h>
#define MaxLength 50            //change MaxLength of name;

struct student {
    int id;
    int class;
    char name[MaxLength + 1];           //since one space is occupied by '\0'
    
} stu ; // alias for struct student : stu

void put();
void access();
void search();
void update();
void delete();
int no_of_id();

int main() {
    while (1) {
        int ch;
        printf("1.Put\t2.Access\t3.Search\t4.Update\t5.Delete\t6.Exit : ");
        scanf("%d",&ch);
        if (ch == 1) put();
        else if (ch == 2) access();
        else if (ch == 3) search();
        else if (ch == 4) update();
        else if (ch == 5) delete();
        else if (ch == 6) break;
        else printf("Invalid Input.\n");
    }
    return 0;
}

void put() {                         // array of structures
    FILE * in = fopen("stu.dat","ab");
    printf("Enter student id : "); fflush(stdin); scanf("%d",&stu.id);  // fflush is to clear buffer; entered id;
    printf("Enter class : "); fflush(stdin); scanf("%d",&stu.class);           //enterd class;
    printf("Enter name : "); fflush(stdin); fgets(stu.name,50,stdin);         //entered name;
    fwrite(&stu,sizeof(stu),1,in);       //write array of structures in bfile
    fclose(in); printf("\n");
}

void access() {
    int id,num = no_of_id();
    FILE * in = fopen("stu.dat","rb");
    printf("ID\tCLASS\tNAME\n");            // written name after class becoz fgets read \n along with it;
    printf("-------------------------------------\n");
    for (int i=0;i<num;i++) {
        fread(&stu,sizeof(stu),1,in);
        printf("%d\t%d\t%s",stu.id,stu.class,stu.name);
    } 
    fclose(in); printf("\n");
}


void search() {
    int num = no_of_id();
    int id,a=0;
    FILE * in = fopen("stu.dat","rb");
    printf("Enter Id : "); scanf("%d",&id);            //read id from user;
    for (int i=0;i<num;i++) {
        fread(&stu,sizeof(stu),1,in);
        if (id == stu.id) {
            printf("ID\tCLASS\tNAME\n");
            printf("---------------------------------\n");
            printf("%d\t%d\t%s",stu.id,stu.class,stu.name);
            a=1;
        }
    }
    if (a==0) printf("ID Not Found!\n"); printf("\n");
}

void update() {
    int num= no_of_id(); int id,a=0; 
    FILE * in = fopen("stu.dat","rb+");
    printf("Enter Id to be Updated : "); scanf("%d",&id);
    for (int i=0;i<num;i++){
        fread(&stu,sizeof(stu),1,in);
        if (id == stu.id){
            printf("Enter New Class : "); fflush(stdin); scanf("%d",&stu.class);
            printf("Enter updated Name : "); fflush(stdin); fgets(stu.name,50,stdin);
            fseek(in,-sizeof(stu),1);
            fwrite(&stu,sizeof(stu),1,in);
            a=1;
            printf("\nUpdated successfully\n\n");
            break;
        }
    }
    if (a=0) printf("NO Record Found!Id cannot be updated.\n\n");
    fclose(in);
}
void delete() {
    int num= no_of_id();int id,a=0;
    FILE * in1 = fopen("stu.dat","rb");
    FILE * in2 = fopen("stu1.dat","wb");
    printf("Enter id to be updated : "); scanf("%d",&id);
    for (int i = 0;i<num;i++) {
        fread(&stu,sizeof(stu),1,in1);
        if (id != stu.id) fwrite(&stu,sizeof(stu),1,in2);
        else a=1;
    }
    fclose(in1);
    fclose(in2);
    if (remove("E:\\c programming\\C_Codes\\stu.dat") == 0) printf("Deleted\n");
    else perror("Error");
    rename("stu1.dat","stu.dat");
    if (a==1) printf("Deleted Successfully\n");
    else printf("ID Not Found!\n\n");
    printf("\n");
    
}

int no_of_id() {        // returns the no of student data stored in file;
    int id=-1,i=0;
    FILE * in = fopen("stu.dat","rb");
    do {
        id = stu.id;
        fread(&stu,sizeof(stu),1,in);
        i++;
    } while (id != stu.id);
     return i-1;
}



// for update del old file and create new file with updated value;
//remember*