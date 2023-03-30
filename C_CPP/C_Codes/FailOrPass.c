#include<stdio.h>

int main() {
    double m1,m2,m3,m4,final_marks;
    printf("Enter marks1, marks2, marks3 and End marks");
    scanf("%lf %lf %lf %lf",&m1,&m2,&m3,&m4);

    final_marks=(m1+m2+m3)*50/75 + m4*50/100;      // contribution of three unit tests as same as final 50-50 %
    final_marks>50 ? printf("Final Marks : %1.2f Status : Pass",final_marks) : printf("Final Marks : %1.2f Status : Fail",final_marks); 
    // ternary operator

    return 0;
}