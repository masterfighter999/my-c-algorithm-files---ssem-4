
/*bst- creation , insertion, deletion, searching*/



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

struct node* findMin(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* delete(struct node* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    
    return root;
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)
        return search(root->left, data);
    
    return search(root->right, data);
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
        printf("Binary Search Tree Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Exit\n");
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
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                root = delete(root, element);
                printf("Element %d deleted successfully.\n", element);
                break;
                
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                struct node* searchResult = search(root, element);
                if (searchResult != NULL)
                    printf("Element %d found in the Binary Search Tree.\n", element);
                else
                    printf("Element %d not found in the Binary Search Tree.\n", element);
                break;
                
            case 4:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
        
        printf("Binary Search Tree: ");
        inorderTraversal(root);
        printf("\n\n");
    }
    
    return 0;
}
