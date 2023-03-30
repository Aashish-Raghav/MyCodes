#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Emp{
int id; char name[50];
}e;
int main(){
  int ch; char op;
do{
printf("\n1)Add  2)DispAll  3)Search  4)Update  5)Delete  6)Exit:\nEnter your choice:\t");
scanf("%d",&ch);
if (ch==1){
  printf("Enter id of employee: "); scanf("%d",&e.id);
  printf("Enter name of employee: "); fflush(stdin); scanf("%s",e.name);
  FILE *fp;
  fp=fopen("edb.dat","ab");
  if (fp==NULL){
    printf("Memory Failure!");
    exit(0);
    fclose(fp);
  }
  else{
      fwrite(&e,sizeof(e),1,fp);
  fclose(fp);
  printf("Data inserted successfully");
  }
}
else if (ch==2){
  FILE *fp;
  fp=fopen("edb.dat","rb");
  if (fp==NULL){
    printf("File can't be open!");
    exit(0);
    fclose(fp);
  }
  else{
      printf("\n-----------------------------------\n");
      printf("EMP-ID\t\tEMP-NAME\n-----------------------------------\n");
      while(fread(&e,sizeof(e),1,fp)){
      printf("%d\t\t%s\n",e.id,e.name);
      }
      printf("-----------------------------------\n");
  fclose(fp);
  }
}
else if (ch==3){
  int tid,flag=0;
    printf("Enter Employee id:\t"); scanf("%d",&tid);
  FILE *fp;
  fp=fopen("edb.dat","rb");
  if (fp==NULL){
    printf("File can't be open!");
    exit(0);
    fclose(fp);
  }
  else{

      while(fread(&e,sizeof(e),1,fp)){
        if(tid==e.id){
        printf("EMP-ID\t\tEMP-NAME\n---------------------------\n");
        printf("%d\t\t%s\n",e.id,e.name);
        flag=1;
        break;
        }
      }
  fclose(fp);
  }
  if(flag==0){
    printf("NoRecordFound: Id does not exits");
  }
}
else if (ch==4){
int tid,flag=0;
FILE *fp,*tfp;
  printf("Enter Employee id:\t");
  scanf("%d",&tid);
  fp=fopen("edb.dat","rb+");
  if (fp==NULL){
    printf("File can't be open!");
    exit(0);
    fclose(fp);
  }
  else{
    while(fread(&e,sizeof(e),1,fp)){
    if(tid==e.id){
      printf("Enter new details for:\n");
      printf("EMP-ID\t\tEMP-NAME\n---------------------------\n");
      printf("%d\t\t%s\n",e.id,e.name);
      printf("Enter name of employee: ");
      fflush(stdin); scanf("%s",e.name);
      fseek(fp,-sizeof(e),1);
      fwrite(&e,sizeof(e),1,fp);
      printf("Data updated successfully");
      flag=1;
      break;
    }
  }
  fclose(fp);
  }
  if(flag==0)
    printf("NoRecordFound: Id does not exits");
}
else if (ch==5){
	int tid,flag=0;
    printf("Enter Employee id:\t");
    scanf("%d",&tid);
  FILE *fp,*tfp;
  fp=fopen("edb.dat","rb");
  tfp=fopen("tedb.dat","wb");
  if (fp==NULL && tfp==NULL){
    printf("File can't be open!");
    exit(0);
    fclose(fp);
    fclose(tfp);
  }
  else{
	while(fread(&e,sizeof(e),1,fp)){
		if(tid!=e.id)
			fwrite(&e,sizeof(e),1,tfp);
		else
			flag=1;
	}
	fclose(fp);
	fclose(tfp);
	remove("edb.dat");
	rename("tedb.dat","edb.dat");
	if(flag==1)
		printf("Record Deleted");
	else
		printf("Record not found");
  }
}
else if (ch==6){
    exit(1);
}
else{
  printf("Invalid Input");
}
printf("\nYou want to perform operations again(y/n):\t"); op=getchar();
}while(op=='Y'||op=='y');
return 0;
}