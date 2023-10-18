#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, element;
    
    while (1) {
        printf("Binary Search Tree Inorder Traversal:\n");
        printf("1. Insert an element\n");
        printf("2. Inorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("Element %d inserted successfully.\n", element);
                break;
                
            case 2:
                printf("Ascending Order: ");
                inorderTraversal(root);
                printf("\n");
                break;
                
            case 3:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
