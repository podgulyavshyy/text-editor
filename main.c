#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct CharLinkedList {
    int index;
    char text;
    struct CharLinkedList* next;
};

struct RowLinkedList{
    int position;
    struct CharLinkedList* head;
    struct RowLinkedList* next;
};

struct RowLinkedList* RowPointer;
struct RowLinkedList* RowHead = NULL;

bool hasStarted = 0;
int numLines = 0;

void NewLine(){
    if(hasStarted == 0){
        hasStarted = 1;
        RowPointer = (struct RowLinkedList*) malloc(sizeof(struct RowLinkedList));
        RowPointer->head = (struct CharLinkedList*) malloc(sizeof(struct CharLinkedList));
        numLines = 1;
        RowPointer->position = 1;
        RowHead = RowPointer;
    }else{
        RowPointer->next = (struct RowLinkedList*) malloc(sizeof (struct RowLinkedList));
        RowPointer = RowPointer->next;
        RowPointer->head = (struct CharLinkedList *) malloc(sizeof(struct CharLinkedList));
        numLines++;
        RowPointer->position = numLines;
    }
}

void Append(){
    if (hasStarted == 0){
        NewLine();
    }
    struct CharLinkedList* current = RowPointer->head;
    while (current->next != NULL){
        current = current->next;
    }

    char input[20];
    printf("Enter text: ");
    scanf("%s", input);
    int i = 0;
    while(input[i] != 0){
        current->next = (struct CharLinkedList*) malloc(sizeof(struct CharLinkedList));
        current->next->index = current->index + 1;
        current = current->next;
        current->text = input[i];
        i++;
    }
    printf("Text added \n");
}

void Print(){

    struct RowLinkedList* currentRow = RowHead;
    while(true){
        if(currentRow == NULL){
            printf("Nothing to print, add some text! \n");
            break;
        }
        struct CharLinkedList* currentChar = currentRow->head;
        while(true){
            if (currentChar->text == 0){
                if (currentChar->next == NULL){
                    break;
                }
                currentChar = currentChar->next;
                continue;
            }
            char character = currentChar->text;
            printf("%c", character);
            if (currentChar->next == NULL){
                break;
            }
            currentChar = currentChar->next;
        }
        printf("\n");
        if (currentRow->next == NULL) break;
        currentRow = currentRow->next;
    }
};

void NotImplemented(){
    printf("The command is not implemented! \n");
}

int main() {
    struct CharLinkedList CharLinkedList = {.next = NULL};
    struct RowLinkedList RowLinkedList = {.next = NULL};
    while (true) {
        int command;
        printf("Choose the command: ");
        if(scanf("%d", &command) == 0){
            printf("Must be an integer! \n");
            fflush(stdin);
            continue;
        }
        if (!(command >= 0 && command <= 7)){
            NotImplemented();
        }
        switch (command) {
            case 1:
                Append();
                break;
            case 2:
                NewLine();
                break;
            case 3:
                NotImplemented();
                break;
            case 4:
                Print();
                break;
            case 5:
                NotImplemented();
                break;
            case 6:
                NotImplemented();
                break;
            default:
                continue;
        }
    }
}
