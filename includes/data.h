struct Node
{
    struct Node* next;
    char name[30];
    char surname[30];
    char phone[30];
    char email[50];
};
typedef struct Node *node;