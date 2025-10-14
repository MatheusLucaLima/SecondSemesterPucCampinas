#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pacient{
    char name[100];
    int age;
    int id;
    struct Pacient *next;
}pacient;

typedef struct pacient_pointer{
    pacient *first;
    pacient *last;
}pointers;

pacient *add_pacient(pacient *first);

int main(){
    pacient *first = NULL;
    pointers *help = NULL;

}

pacient *add_pacient(pacient *first){
    pacient *new_pacient = (pacient *) malloc (sizeof(pacient));
    if (new_pacient == NULL){
        printf("Error on memory allocation.\n");
        exit(-1);
    }
    printf("Pacient's name:\n");
    char name[100];
    scanf(" %[^\n]", name);
    printf("Pacient's age:\n");
    int age;
    scanf(" %d", &age);
    printf("Pacient's id:\n");

}