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
};
typedef struct Node *node;