#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model/Model.h"

Node *newNode (char * name, int day, int month, int year){
    Node *temp = (Node*) malloc (sizeof(Node));

    strcpy(temp->name, name);
    temp->day = day;
    temp->month = month;
    temp->year = year;

    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

int DecodeM(char * m){

    int p = 0;
    char month[13][100] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    for (int i=0; i<12; i++){
        if (strcmp(month[i], m) == 0){
            p = i+1;
            break;
        }
    }

    return p;
}

void PushNode(int d, char* m, int y, char* n){

    //Semakin tua semakin ke belakang
    //puts("OK1");
    int md = DecodeM((char *) m);
    //puts("OK2");
    Node *temp = newNode((char*)n, d, md, y);
    //puts("OK3");

    if (!head){
        head = tail = temp;
        //printf ("%s %s\n", head->name, tail->name);
    }

    else if(temp->year > tail->year) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else if(temp->year == tail->year && temp->month > tail->month) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    
    }
    else if(temp->year == tail->year && temp->month == tail->month && temp->day > tail->day) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
    ///////////////////
    else if (temp->year < head->year){
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else if (temp->year == head->year && temp->month < head->month){
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else if (temp->year == head->year && temp->month == head->month && temp->day < head->day){
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else {
        Node *now = head;
        //Cari node didepan temp
        while (true){
            if (now->year > temp->year) break;
            else if (now->year == temp->year){
                if (now->month > temp->month) break;
                else if (now->month == temp->month){
                    if (now->day > temp->day) break;
                    else break;
                }
            }
            now = now->next;
        }

        temp->next = now;
        now->prev->next = temp;
        temp->prev = now->prev;
        now->prev = temp;
    }

}


void PopNode(){

    if (head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        Node *gudbai = head;
        head = gudbai->next;
        head->prev = NULL;
        gudbai->next = NULL;
        free(gudbai);
    }
}

void Results(int res){

    char months[13][100] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    if (res >= 0){
        printf ("All patients get the cure, %d cure left\n", res);
    }
    else {
        printf ("Need %d more cure\n", res*-1);

        Node *now = head;
        while (now){

            printf ("%d %s %d - %s\n", now->day, months[now->month - 1], now->year, now->name);
            now = now->next;

        }
    }
}

void PrintRest(){
    char months[13][100] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    Node *now = head;
        while (now){
            printf ("%d %s %d - %s\n", now->day, months[now->month - 1], now->year, now->name);
            now = now->next;
        }
}