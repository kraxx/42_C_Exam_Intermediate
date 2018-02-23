/*
CLONE_LIST
Assignment name  : clone_list
Expected files   : clone_list.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Given a linked list with the following structure :
    struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
    };
where :
    - next pointer points to the next node.
    - other pointer points to any node in the list (another node, itself or NULL).
Write a function to create a copy of this list (allocate new memory).
You cannot modify the structure, you cannot modify the list you are given.
The function must be declared as follows:
    struct s_node *clone_list(struct s_node *node);
*/