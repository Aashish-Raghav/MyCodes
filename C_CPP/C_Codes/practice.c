//using %c,vowels in str,char in str,;
//input 2d vector using struct and return sum using fxn.
//struct to add complex no. using arrow op
//makw structure to store bank account details of customer
//fwrite ,fread 

#include<stdio.h>
#include<stdlib.h>
#define MaxLength 50            //change MaxLength of name;

typedef struct student {
    int id;
    int class;
    char name[MaxLength + 1];           //since one space is occupied by '\0'
    
} stu ; // alias for struct student : stu

int no_of_id();


int main() {
    while (1) {
        int ch;
        printf("1.Put\t2.Access\t3.Search\t4.Update\t5.Exit : ");
        scanf("%d",&ch);
        if (ch == 1) {
            stu s1[1];                          // array of structures
            FILE * in = fopen("student.txt","ab");
            printf("Enter student id : ");      
            fflush(stdin);                      // fflush is to clear buffer;
            scanf("%d",&s1[0].id);              //entered id;
            printf("Enter class : ");           
            fflush(stdin);
            scanf("%d",&s1[0].class);           //enterd class;
            printf("Enter name : ");
            fflush(stdin);
            fgets(s1[0].name,50,stdin);         //entered name;

            fwrite(s1,sizeof(stu),1,in);       //write array of structures in bfile
            fclose(in);
            printf("\n");

        } else if (ch == 2) {
            stu s1[1];
            int id,num = no_of_id();
            FILE * in = fopen("student.txt","rb");
            printf("ID\tCLASS\tNAME\n");            // written name after class becoz fgets read \n along with it;
            printf("-------------------------------------\n");
            for (int i=0;i<num;i++) {
                fread(s1,sizeof(stu),1,in);
                printf("%d\t%d\t%s",s1[0].id,s1[0].class,s1[0].name);
            }
            fclose(in);
            printf("\n");

        } else if (ch == 3) {
            stu s1[1];
            int num = no_of_id();
            int id,a=0;
            FILE * in = fopen("student.txt","rb");
            printf("Enter Id : ");
            scanf("%d",&id);            //read id from user;
            for (int i=0;i<num;i++) {
                fread(s1,sizeof(stu),1,in);
                if (id == s1[0].id) {
                    printf("ID\tCLASS\tNAME\n");
                    printf("---------------------------------\n");
                    printf("%d\t%d\t%s",s1[0].id,s1[0].class,s1[0].name);
                    a=1;
                }
            }
            if (a==0) printf("ID Not Found!\n");
            printf("\n");

        } else if (ch == 4) {
            stu s1[1];
            int num= no_of_id();
            int id,a=0;
            FILE * in1 = fopen("student.txt","rb");
            FILE * in2 = fopen("student1.txt","wb");
            printf("Enter id to be updated : ");
            scanf("%d",&id);
            for (int i = 0;i<num;i++) {
                fread(s1,sizeof(stu),1,in1);
                if (id == s1[0].id) {
                    printf("Enter updated class : ");
                    fflush(stdin);
                    scanf("%d",&s1[0].class);
                    printf("Enter updated name : ");
                    fflush(stdin);
                    fgets(s1[0].name,50,stdin);
                    fwrite(s1,sizeof(stu),1,in2);
                    a=1;
                } else {
                    fwrite(s1,sizeof(stu),1,in2);
                }
            }
            fclose(in1);
            fclose(in2);

            if (remove("E:\\c programming\\C_Codes\\student.txt") == 0) printf("Deleted\n");
            else perror("Error");
            rename("student1.txt","student.txt");
            
            if (a==1) printf("Updated Successfully\n");
            else printf("ID Not Found!");
            printf("\n");

        }
        else if (ch == 5) break;
        else printf("Invalid Input.\n");
                  
    }
    return 0;
}

int no_of_id() {        // returns the no of student data stored in file;
    stu s1[1];
    int id=-1,i=0;
    FILE * in = fopen("student.txt","rb");
    do {
        id = s1[0].id;
        fread(s1,sizeof(stu),1,in);
        i++;
    } while (id != s1[0].id);
     return i-1;
}


// for update del old file and create new file with updated value;
//remember*