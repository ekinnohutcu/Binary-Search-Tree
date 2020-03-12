#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>

//Ekin Nohutcu 150116067
//References: https://riptutorial.com/c/example/13404/inserting-a-node-at-the-nth-position
//            https://stackoverflow.com/questions/21211701/given-a-bst-and-its-root-print-all-sequences-of-nodes-which-give-rise-to-the-sa/24398114#24398114
//            https://stackoverflow.com/questions/1701612/find-number-of-permutations-of-a-given-sequence-of-integers-which-yield-the-same

//This code requires input from input file.
struct bstnode {
    int data;
    bool b;
    struct bstnode *l;
    struct bstnode *r;
};

struct sequences {
    struct node *number;
    struct sequences *next;

};

typedef struct bstnode bstnode;
typedef struct sequences seq;
struct node *root = NULL;
seq *header = NULL;



struct bstnode *insertBST(struct bstnode *root, int data) {
    if (root == NULL) {
        struct bstnode *newNode = malloc(sizeof(struct bstnode));
        newNode->data = data;
        newNode->l = NULL;
        newNode->r = NULL;
        return newNode;
    }

    if (data < root->data) {

        root->l = insertBST(root->l, data);
    } else if (data > root->data) {

        root->r = insertBST(root->r, data);
    }


    return root;
}

void insertnthpos(bstnode *p, int n) {
    int i;
    struct sequences *temp1 = (struct sequences *) malloc(sizeof(struct sequences));
    temp1->number = p;
    temp1->next = NULL;
    if (n == 0) {
        temp1->next = header;
        header = temp1;
        return;
    }
    struct sequences *temp2 = header;
    for (i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void append(int new_data)
{
    seq* new_node = (seq*) malloc(sizeof(seq));

    seq*last = header;


    new_node->number  = new_data;

    new_node->next = NULL;


    if (header == NULL)
    {
        header = new_node;
        return;
    }


    while (last->next != NULL)
        last = last->next;


    last->next = new_node;
    return;
}


void inorder(struct bstnode *root) {
    if (root == NULL) return;
    inorder(root->l);
    printf("%d ->", root->data);
    inorder(root->r);
}




int main() {


    FILE *file;
    int x;

    file = fopen("input.txt", "r");

    while (!feof(file)) {

        fscanf(file, "%d", &x);
        if (root == NULL) {
            root = insertBST(root, x);
            append(x);
        } else{

            insertBST(root, x);
            append(x);

        }
        

    }
    fclose(file);
    inorder(root);




    return 0;


}