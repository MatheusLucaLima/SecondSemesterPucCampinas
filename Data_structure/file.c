#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient{
    char name[100];
    int age;
    int id;
    struct Patient *next;
}patient;


void add_patient(pacient *first);
void treat_patient

int main(){
    patient *first = NULL;
    add_patient(first);

}

void add_patient(patient *first){
    patient *new_patient = (patient *) malloc (sizeof(patient));
    if (new_patient == NULL){
        printf("Error on memory allocation.\n");
        exit(-1);
    }
    printf("Patient's name:\n");
    char name[100];
    scanf(" %[^\n]", name);
    printf("Patient's age:\n");
    int age;
    scanf(" %d", &age);
    printf("Patient's id:\n");
    int id;
    scanf(" %d", &id);

    strcpy(new_patient->name, name);
    new_patient -> age = age;
    new_patient -> id = id;
    new_patient -> next = NULL;

    if (first == NULL){
        first = new_patient;
        return;
    }

    patient *aux = first;
    
    while(aux){
        if(aux->next == NULL){
            aux -> next = new_patient;
            break;
        }
        aux = aux -> next;
    }
    

}