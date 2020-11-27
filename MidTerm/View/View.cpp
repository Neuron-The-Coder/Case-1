#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Controller/Controller.h"


int main(){

    int total, available;

    scanf ("%d %d", &total, &available);
    getchar();

    for (int i=0; i<total; i++){
        int d;
        char m[255];
        int y;
        char name[255];

        scanf("%d %[^ ] %d - %[^\n]", &d, m, &y, name);
        getchar();
        //printf ("%d %s %d - %s\n", d, m, y, name);

        PushNode(d, (char*)m, y, (char *) name);
    }

    for (int i=0; i<available; i++) PopNode();
    Results(available - total);


    return 0;
}
