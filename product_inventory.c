#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

// User Defined DataType - Structure for Student data
struct Student
{
    int rno;
    char name[50];
    int std;
    int marks;
    int active;
};

#define SIZE 1000

struct Student records[SIZE];
int studentCount = 0;
int rnos = 1;

// Function prototypes
void addStudent();
void updateStudentById();
void deleteStudentById();
void displayStudents();
void searchStudentById();
void sortStudentByMarks();
void printStudent(struct Student s);
void mainMenu();
void logInUser();

// Function to print a single student record
void printStudent(struct Student s)
{
    printf("\n%d\t%s\t%d\t%d", s.rno, s.name, s.std, s.marks);
}

// Function to add a new student
void addStudent()
{
    struct Student s;

    if(studentCount == SIZE)
    {
        printf("\nStudent List is full.");
        return;
    }

    s.rno = rnos;
    fflush(stdin);

    printf("\nEnter Name : ");
    gets(s.name);

    printf("\nEnter Std : ");
    scanf("%d", &s.std);

    printf("\nEnter Marks : ");
    scanf("%d", &s.marks);

    s.active = 1;

    records[studentCount] = s;
    studentCount++;
    rnos++;

    printf("\nStudent record successfully inserted!");
}

// Function to update student by ID
void updateStudentById()
{
    int i, rno, flag = 1;

    printf("\nEnter Rno which you want to update: ");
    scanf("%d", &rno);

    for(i = 0; i < studentCount; i++)
    {
        if(records[i].rno == rno && records[i].active == 1)
        {
            fflush(stdin);

            printf("\nEnter Name : ");
            gets(records[i].name);

            printf("\nEnter Std : ");
            scanf("%d", &records[i].std);

            printf("\nEnter Marks : ");
            scanf("%d", &records[i].marks);

            flag = 0;
            printf("\nStudent Rno : %d is updated successfully.", rno);
            break;
        }
    }

    if(flag)
    {
        printf("\nStudent Rno : %d is not found in student records.", rno);
    }
}

// Function to delete student by ID
void deleteStudentById()
{
    int i, rno, flag = 1;

    printf("\nEnter Rno which you want to delete: ");
    scanf("%d", &rno);

    for(i = 0; i < studentCount; i++)
    {
        if(records[i].rno == rno && records[i].active == 1)
        {
            records[i].active = 0;
            printf("\nStudent Rno : %d is deleted from list.", rno);
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        printf("\nStudent Rno : %d is not found in student records.", rno);
    }
}

// Function to display all active students
void displayStudents()
{
    int i;

    if(studentCount == 0)
    {
        printf("\nList of student records is empty");
        return;
    }

    printf("\n\nStudent Records:");
    printf("\nRno\tName\tStd\tMarks");
    printf("\n--------------------------------");

    for(i = 0; i < studentCount; i++)
    {
        if(records[i].active == 1)
        {
            printStudent(records[i]);
        }
    }
}

// Function to search student by ID
void searchStudentById()
{
    int i, rno, flag = 1;

    printf("\nEnter Rno to search student record: ");
    scanf("%d", &rno);

    for(i = 0; i < studentCount; i++)
    {
        if(records[i].rno == rno && records[i].active == 1)
        {
            printf("\nRecord Found:");
            printf("\nRno\tName\tStd\tMarks");
            printf("\n--------------------------------");
            printStudent(records[i]);
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        printf("\nStudent Rno : %d is not found in student records.", rno);
    }
}

// Function to sort students by marks (descending order)
void sortStudentByMarks()
{
    struct Student temp;
    int i, j;

    if(studentCount == 0)
    {
        printf("\nList of student records is empty");
        return;
    }

    struct Student activeRecords[SIZE];
    int activeCount = 0;

    for(i = 0; i < studentCount; i++)
    {
        if(records[i].active == 1)
        {
            activeRecords[activeCount] = records[i];
            activeCount++;
        }
    }

    for(i = 0; i < activeCount; i++)
    {
        for(j = i + 1; j < activeCount; j++)
        {
            if(activeRecords[i].marks < activeRecords[j].marks)
            {
                temp = activeRecords[i];
                activeRecords[i] = activeRecords[j];
                activeRecords[j] = temp;
            }
        }
    }

    printf("\n\nStudents Sorted by Marks (Highest to Lowest):");
    printf("\nRno\tName\tStd\tMarks");
    printf("\n--------------------------------");

    for(i = 0; i < activeCount; i++)
    {
        printStudent(activeRecords[i]);
    }
}

// Main menu
void mainMenu()
{
    printf("\n\n======== STUDENT MANAGEMENT SYSTEM ========");
    printf("\n1) Add Student");
    printf("\n2) Update Student By ID");
    printf("\n3) Delete Student By ID");
    printf("\n4) Display All Students");
    printf("\n5) Search Student By ID");
    printf("\n6) Sort Students By Marks");
    printf("\n7) Exit");
    printf("\n===========================================");
    printf("\nEnter your choice: ");
}

void logInUser(){
    int i , password , flag = 0;
    char username[30];

    for (i = 0; i < 3; i++){
        printf("\nEnter you Detail : Try %d" , i+1);
        printf("\n============================");
        printf("\nEnter the username : ");
        scanf("\n%s" , &username);
        printf("\nEnter the Password : ");
        scanf("\n%d" , &password);

        if(strcmp(username,"admin")==0 && password == 1234)
        {
            flag = 1;
            printf("Log In successfully");
            mainMenu();
            break;
        }else{
            printf("Access Denied...");
        }
    } 
    
    if (flag = 0){
        printf("Access Denied. Exiting program...");
        exit(0);
    }
}


// Main function
int main()
{ 
    logInUser();
    int choice;
    do
    {
    
    scanf("%d", &choice);

    switch(choice)
    {
    case 1: addStudent(); 
            break;
    case 2: updateStudentById(); 
            break;
    case 3: deleteStudentById(); 
            break;
    case 4: displayStudents(); 
            break;
    case 5: searchStudentById(); 
            break;
    case 6: sortStudentByMarks(); 
            break;
    case 7:
        printf("\nStudent Application Exit");
        exit(0);
    default:
        printf("\nInvalid choice! Please try again.");
    }

    printf("\n\nPress any key to continue...");
    getch();

    } while(choice != 7);
        
    return 0;
            
        
}

    
      


