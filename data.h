struct address
{
    char* name;
    char* surname;
    char* phone;
    char* email;
};

struct Node
{
    struct Node* next;
    struct address entry;
   // int index;
};
typedef struct Node *node;