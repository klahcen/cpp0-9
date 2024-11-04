#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int val;
    struct s_list *next;
} t_list;

int main()
{
    t_list *head = NULL;  
    t_list *node = NULL;  
    t_list *tail = NULL;  
    int i;

    for (i = 0; i < 10; i++)
    {
        node = malloc(sizeof(t_list));
        node->val = i;
        node->next = NULL; 

        if (!head) 
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node; 
    }


    node = head;
    while (node)
    {
        printf("val: %d\n", node->val);
        node = node->next; 
    }

    return 0;
}