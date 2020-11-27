struct Node {
    char name[255];
    int day;
    int month;
    int year;

    Node *next;
    Node *prev;

} *head = NULL, *tail = NULL;
