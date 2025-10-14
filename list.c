#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct client{
    char name[100];
    long id;
    long phone;
    struct client *next;
};

struct client *signup (struct client *head);
void show_clients (struct client *head);
struct client *delete_byId (struct client *head);
void show_client_byId (struct client *head);
struct client *delete_all (struct client *head);


int main() {
    struct client *head = NULL;
    
    int i = 0;
    
    do{
        printf("---------------------------------");
        printf("Type the desired function:\n");
        printf("0-Close the program.\n");
        printf("1-Sign up a client.\n");
        printf("2-Show all clients.\n");
        printf("3-Delete a client by ID.\n");
        printf("4-Show client by ID\n");
        scanf(" %d", &i);
        switch(i)
        {
            case 0:
            {
                head = delete_all(head);
                show_clients(head);
            }break;
            case 1:
            {
                head = signup(head);
            }break;
            case 2:
            {
                show_clients(head);
            }break;
            case 3:
            {
                head = delete_byId(head);
            }break;
            case 4:
            {
                show_client_byId (head);
            }break;
            default:
            {
                printf("Invalid input.\nTry again!\n\n");
            }
        }
        
    
    }while(i!=0);
    

    return 0;
}

struct client *signup (struct client *head){
    
    struct client *new_client = (struct client *) malloc (sizeof(struct client));
    
    if (new_client == NULL){
        printf("Error in memory allocation.\n");
        exit(-1);
    }
    
    printf("Client's name:\n");
    char name[100];
    scanf(" %[^\n]", name);
    printf("Client's ID:\n");
    long id;
    scanf("%ld", &id);
    printf("Client's phone:\n");
    long phone;
    scanf("%ld", &phone);
    
    //Assignments
    strcpy(new_client -> name, name);
    new_client -> id = id;
    new_client -> phone = phone;
    
    new_client -> next = head;
        
    return new_client;
}

void show_clients (struct client *head){
    if(head == NULL){
        printf("This no client registered.\n");
        return;
    }
    struct client *aux = head;
    int i = 1;
    while (aux){
        printf("\n\n-----------Client %d-----------\n\n", i);
        printf("Client's name: %s\n", aux->name);
        printf("Client's ID: %ld\n", aux->id);
        printf("Client's phone: %ld\n", aux->phone);
        i++;
        aux = aux->next;
    }
}


struct client *delete_byId (struct client *head){
    if(head == NULL){
        printf("There is not any client registered yet!\n");
        return head;
    }
    struct client *aux = head;
    struct client *previous = NULL;
    printf("Type the client's ID to exclude them.\n");
    int id;
    scanf(" %ld", &id);
    while (aux){
        struct client *aux2 = aux;
        if(aux -> id == id){
            if(previous == NULL){
                struct client *aux2 = aux;
                aux = aux -> next;
                free(aux2);
                return aux;
            }
            else{
                aux2->next = aux->next;
                free(aux);
                return head;
            }
        }
        previous = aux;
        aux = aux->next;
    }
    printf("ID not found!\n\n");
    return head;
}

void show_client_byId (struct client *head){
    if(head == NULL){
        printf("There is no client registered.\n");
        return;
    }
    
    struct client *aux = head;
    
    printf("Type the client's ID to see them data.\n");
    long id;
    scanf(" %ld", &id);
    
    while(aux){
        if(aux->id == id){
            printf("\nClient's name: %s\n", aux->name);
            printf("Client's ID: %ld\n", aux->id);
            printf("Client's Phone: %ld\n", aux->phone);
            return;
        }
        aux = aux->next;
    }
    printf("ID not found!\n");
}


struct client *delete_all (struct client *head){
    if(head == NULL){
        return NULL;
    }
    struct client *aux = head;
    while (head){
        head = head -> next;
        free(aux);
        aux = head;
    }
    return head;
}








