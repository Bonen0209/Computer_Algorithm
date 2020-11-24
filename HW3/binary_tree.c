#include <stdio.h>
#include <stdlib.h>

// Node sturcture
struct node { 
    int key; 
    struct node *left, *right; 
};

// Create a new node
struct node *newNode(int key) { 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

// Search the binary tree 
struct node *search(struct node *root, int key) { 
    // If the root is NULL, or the key is on the root
    if (root == NULL || root->key == key) {
        return root;
    }
     
    // Key is greater than root 
    if (root->key < key) {
        return search(root->right, key);
    }
  
    // Key is smaller than root 
    return search(root->left, key); 
}

// Maximum value of the binary tree
int maximum(struct node *root) {    
    struct node *current = root;

    // Keep going right
    while (current->right != NULL) {
        current = current->right;
    }

    return current->key; 
}

// Minimum value of the binary tree
int minimum(struct node *root) {
    struct node *current = root;

    // Keep going left
    while (current->left != NULL) {
        current = current->left;
    }

    return current->key;
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    // If the root is NULL, create a new one
    if (root == NULL) {
        return newNode(key); 
    }
    
    // Comparison
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
            
    return root; 
}

// Delete a node
struct node *deleteNode(struct node *root, int key) {
    // If the root is NULL
    if (root == NULL) {
        return root; 
    }

    // Search the node
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else { 
        // Node with only one child or no child 
        if (root->left == NULL) { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // Node with two children
        struct node* temp;
        temp = root->right; 
            while (temp->left) {
                temp = temp->left;
            }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Successor
struct node *successor(struct node *root, int key) {
    // If the root is NULL
    if (root == NULL) {
        return root;
    }

    struct node *suc;
  
    // Search the key
    while (root != NULL) { 
  
        // If root is given key
        if (root->key == key) { 
            if (root->right) { 
                suc = root->right; 
                while (suc->left) {
                    suc = suc->left;
                }
            }
  
            return suc; 
        }
        else if (root->key > key) { 
            suc = root; 
            root = root->left;
        }
    }

    return suc;
}

// Predecessor
struct node *predecessor(struct node *root, int key) {
    // If the root is NULL
    if (root == NULL) {
        return root;
    }

    struct node *pre;
  
    // Search the key
    while (root != NULL) { 
  
        // If root is given key
        if (root->key == key) {
            if (root->left) { 
                pre = root->left; 
                while (pre->right) {
                    pre = pre->right;
                } 
            } 
  
            return pre; 
        } 
        else if (root->key < key) { 
            pre = root; 
            root = root->right; 
        }
    }

    return pre;
}

int main() {
    struct node *root = NULL;

    while (true) {
        int option, key;
        printf("1:Search\n");
        printf("2:Maximum\n");
        printf("3:Minimum\n");
        printf("4:Sucessor\n");
        printf("5:Predecessor\n");
        printf("6:Insert\n");
        printf("7:Delete\n");
        printf("8:Leave\n");
        printf("Please select your option to do to the Binary Tree: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Please input a key: ");
                scanf("%d", &key);
                if (search(root, key) == NULL) {
                    printf("Not find\n");
                }
                else {
                    printf("Find");
                }
                break;
            case 2:
                printf("%d", maximum(root));
                break;
            case 3:
                printf("%d", minimum(root));
                break;
            case 4:
                printf("Please input a key: ");
                scanf("%d", &key);
                if (successor(root, key) == NULL) {
                    printf("Not find\n");
                }
                else {
                    printf("%d", successor(root, key)->key);
                }
                break;
            case 5:
                printf("Please input a key: ");
                scanf("%d", &key);
                if (predecessor(root, key) == NULL) {
                    printf("Not find\n");
                }
                else {
                    printf("%d", predecessor(root, key)->key);
                }
                break;
            case 6:
                printf("Please input a key: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 7:
                printf("Please input a key: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            default:
                break;
        }
    }

    return 0;
}