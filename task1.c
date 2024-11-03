#include <stdio.h>
#include <string.h>

// Define a structure for student data 
typedef struct Student {
    int id;        // Stduent ID
    char name[50]; // Stduent name
    float gpa;     // Student GPA
} Student;

int main(){
    
    int arraysize;
    printf("please enter number of student : ");
    scanf("%d", &arraysize );

    Student array[arraysize]; 
    for(int i=0 ; i<arraysize ; i++){
     printf("Enter id of student %d : ", i+1 );
     	scanf("%d",&array[i].id);
     printf("Enter name  of student %d : ", i+1 );
        scanf("%s",array[i].name);
     printf("Enter GPA of student %d : ", i+1 );
        scanf("%f",&array[i].gpa);

    
    }

    for(int i=0; i<arraysize; i++){
    printf("ID: %d ",array[i].id);
    printf("Name: %s ",array[i].name);
    printf("GPA: %.2f ",array[i].gpa);
    printf("\n");
    
    
    }
  
    return 0;
}
