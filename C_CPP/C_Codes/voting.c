#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct voting {
    char name[50];
    int num;
} vt;

int main() {
    vt vote[8];
    int validVotes=0,SpoiltVotes=0,max=0,ch;
    char name[50],lname[25];
    char invalid[1][1];
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\voting.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\voting_results.txt","w");
    for (int i = 0;i <7;i++) {
        fflush(stdin);
        fscanf(in,"%s %s",name,lname);
        strcat(name," ");
        strcat(name,lname); 
        strcpy(vote[i+1].name,name);    
        vote[i+1].num = 0;
        
    }
    fscanf(in,"%d",&ch);

    while (ch != 0) {
        if (ch > 7 || ch <1){
            fprintf(out,"Invalid vote : %d\n",ch);
            SpoiltVotes++;
        } else {
            vote[ch].num++;
            validVotes++;
        }
        fscanf(in,"%d",&ch);
    }
    fprintf(out,"\n");

    fprintf(out,"No of voters : %d\nNo of valid voters : %d\nNo of Spoilt Votes : %d\n\n",validVotes+SpoiltVotes,validVotes,SpoiltVotes);
    fprintf(out,"Candidate\t\t\tScore\n\n");
    for (int i=0;i <7;i++) {
        fprintf(out,"%-20s %2d\n",vote[i+1].name,vote[i+1].num);
        if ( vote[i+1].num > max) max = vote[i+1].num;
    }
    fprintf(out,"\n\nThe Winner(s):\n");

    for (int i=0;i<8;i++) {
        if (vote[i+1].num == max) fprintf(out,"%s\n",vote[i+1].name);
    }

}
