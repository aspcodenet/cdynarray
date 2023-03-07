#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int BirthYear;
    char FirstName[50];
    char LastName[50];
    char City[50];
}Student;

void PrintStudent(const Student *p){
    printf("Student information:\n");
    printf("%s %s\n",p->FirstName, p->LastName);
    printf("%s Birth year:%d\n",p->City, p->BirthYear);
}


void InputStudent(Student *p){
    printf("Ny student:\n");
    printf("First name:");
    scanf(" %s", p->FirstName);
    printf("Last name:");
    scanf(" %s", p->LastName);
    printf("City:");
    scanf(" %s", p->City);
    printf("Birth year:");
    scanf(" %d", &p->BirthYear);
}

void Lab1(){
    Student student1;
    Student student2;

    InputStudent(&student1);
    InputStudent(&student2);

    PrintStudent(&student1);
    PrintStudent(&student2);
}

void Lab2(){
    Student studentLista[10];
    int antal = 0;
    
    while(true){
        InputStudent(&studentLista[antal]);
        antal++;
        if(antal == 10)
            break;

        char cont[10];
        printf("Eter one more Yes/No?");
        scanf(" %s", cont);
        strupr(cont);
        
        if(!strcmp(cont, "YES") || !strcmp(cont, "Y")) continue;

        break;
    }

    Student *oldestStudent = &studentLista[0];
    for(int i = 0; i < antal;i++)
        if(studentLista[i].BirthYear < oldestStudent->BirthYear)
            oldestStudent = &studentLista[i];


    for(int i = 0; i < antal;i++)
        PrintStudent(&studentLista[i]);
}




// FÖRSTORA OCH FÖRMINSKA
//      17 kunder
//      add 1 kund -> 18 st

// LIVSLÄNGD
//   stack lever -> out of scope
//   kontrollera livslängd

// -> HEAP allokeringer


void test(){
    char *namn2;
    // size_t = hur många                    
    //malloc kommer ALLOKERA (Paxa) size_t antal bytes
    // på heapen - inte stacken
    namn2 = (char *)malloc( sizeof(char) *  12);
    scanf(" %s", namn2);
    printf("%s\n",namn2);
    free(namn2);

    char namn[12];
    scanf(" %s", namn);
    printf("%s\n",namn);
}

int main(){
    int *lista; // lista kommer innehållas en minnesadress
                    // där en eller flera INTS ligger efter varandra 

    lista = (int *)malloc( sizeof(int) *  5);
    lista[0]=12;
    lista[1]=123;
    lista[2]=120;
    lista[3]=1120;
    lista[4]=4234;
    lista = (int *)realloc(lista, sizeof(int) *  6);
    lista[5] = 34432;
    lista = (int *)realloc(lista, sizeof(int) *  7);
    lista[6] = 31;

    free(lista);


    double *temperaturer; // lista kommer innehållas en minnesadress
                    // där en eller flera FLOATS ligger efter varandra
    temperaturer = (double *)malloc( sizeof(double) *  10);
    int antal = 0;
    temperaturer[0] = 12;
    antal++;
    temperaturer[1] = 99;
    antal++;
    temperaturer[2] = 100;
    antal++;


    //char namn[12]; // namn är en pekare till 12 bytes - på stacken
    while(1){
        test();

    }
    return 0;
}