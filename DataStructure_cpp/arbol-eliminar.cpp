#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
};

Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void insert(Node* &root, int key)
{
    Node* toinsert = newNode(key);
    Node* curr = root;
    Node* prev = NULL;

    while (curr != NULL) {
        prev = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (prev == NULL) {
        prev = toinsert;
        root = prev;
    }

    else if (key < prev->key){
        prev->left = toinsert;
    }

    else{
        prev->right = toinsert;
    }
}

Node* getmin( Node* root)
{
    Node* curr = root;

    while (curr && curr->left) {
        curr = curr->left;
    }

    return curr;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete(root);
            return temp;
        }

        Node* temp = getmin(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void mostrarA(Node *arbol, int contador) {
    //contador = 0;
    if(arbol != NULL) {
        mostrarA(arbol->right, contador+1);

        for(int i = 0; i < contador; i++) {
            cout<<"   ";
        }

        cout<<arbol->key<<endl;

        mostrarA(arbol->left, contador+1);
    }
}

int c = 0;

int main() {
    Node *root = NULL;
    insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 6);
    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 7);
    //inorder(root);
    mostrarA(root, c);
    cout << "\n";
    deleteNode(root, 5);
    //inorder(root);
    mostrarA(root, c);
}