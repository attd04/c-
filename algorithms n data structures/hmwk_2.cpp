//
//  main.cpp
//  alg 2 a
//
//  Created by Autumn Tiede on 11/10/23.
//
// create binary tree with integer elements. implement insert, search, print, and delte operations and perform the following actions:

// a) insert the negative numbers from the tree in the queue implemented as doubly linked list
// b) insert all non negative numbers from the tree in the queue implemented as doubly linked list
// c) Remove all elements from the tree that are greater than 10 by input then to the stack implemented as a singly-linked list.
// d) Remove all items from the queue and the stack by printing them on the screen.

#include <iostream>
#include <queue>
using namespace std;

// stack
class Node_ss {
public:
    int data_ss;
    Node_ss* next;

    // constructor to initialize a node
    Node_ss(int value) : data_ss(value), next(nullptr) {}
};

// represents stack implemented as singly linked list
class Stack {
public:
    Node_ss* top;  // Pointer to the top of the stack
    // initialize empty stack
    Stack() : top(nullptr) {}

    // push (insert) new element onto the stack
    void push(int value) {
        Node_ss* newNode = new Node_ss(value);
        newNode->next = top;
        top = newNode;
    }

    // pop (delete) element from the stack
    void pop() {
        if (top != nullptr) {
            Node_ss* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "stack is empty." << endl;
        }
    }

    // print elements of stack
    void print() {
        Node_ss* current = top;
        while (current != nullptr) {
            cout << current->data_ss << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    bool isEmpty() {
           return top == nullptr;
       }
};

// doubly linked list
class Node_double {
public:
    int data_double;
    Node_double* prev;
    Node_double* next;

    // Constructor to initialize a node
    Node_double(int value) : data_double(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node_double* head;  // Pointer to the head of the list
    
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insert_double(int value) {
        Node_double* newNode = new Node_double(value);
        if (head == nullptr) {
            // If the list is empty, set the new node as the head
            head = newNode;
        } else {
            // Otherwise, traverse the list to the end and insert the new node
            Node_double* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    
    void deleteAll_double() {
            Node_double* current = head;
            while (current != nullptr) {
                Node_double* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
        }

    // print the elements
    void print_double() {
        Node_double* current = head;
        while (current != nullptr) {
            std::cout << current->data_double << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    bool isEmpty_double() {
            return head == nullptr;
        }
};

// tree
class Node { // creates nodes for binary tree
public:
    int key;
    Node* left; // accessible members outside of class
    Node* right;

    Node(int k) { // constructor
        key = k;
        left = right = nullptr; // when node created, has no left or right child
    }
};

class BinaryTree { // private class for the binary tree
private:
    Node* root;

    Node* inputTree(Node* root, int key) { // inserting elements to tree
        if (root == nullptr) { // if root = 0
            return new Node(key); // create new node
        }

        if (key < root->key) { // putting new node left or right depending on value
            root->left = inputTree(root->left, key);
        } else if (key > root->key) {
            root->right = inputTree(root->right, key);
        }

        return root;
    }

    void inputTreeInverse(Node* root) { // putting items in starting from left
        if (root != nullptr) {
            inputTreeInverse(root->left);
            cout << root->key << " ";
            inputTreeInverse(root->right);
        }
    }

    Node* searchTree(Node* root, int key) { // for searching for an item
        if (root == nullptr || root->key == key) { // returns value if found
            return root;
        }

        if (key < root->key) {
            return searchTree(root->left, key);
        }

        return searchTree(root->right, key);
    }

    Node* deleteTree(Node* root, int key) { // deletes elements
        if (root == nullptr) { // if doesnt exist, return nothing
            return root;
        }

        if (key < root->key) { // checking right and left sides
            root->left = deleteTree(root->left, key);
        } else if (key > root->key) {
            root->right = deleteTree(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->key = temp->key;
            root->right = deleteTree(root->right, temp->key);
        }
        return root;
    }

    void collectNegatives(Node* root, queue<int>& negativesQueue) { // collects neg elements
        if (root != nullptr) {
            collectNegatives(root->left, negativesQueue);
            if (root->key < 0) {
                negativesQueue.push(root->key);
            }
            collectNegatives(root->right, negativesQueue);
        }
    }
    
    void collectPositives(Node* root, queue<int>& positiveQueue) { // deletes elements
        if (root != nullptr) {
            collectPositives(root->left, positiveQueue);
            if (root->key > 0) {
                positiveQueue.push(root->key);
            }
            collectPositives(root->right, positiveQueue);
        }
    }

public:
    BinaryTree() { // initializing values
        root = nullptr;
    }

    void insert(int key) {
        root = inputTree(root, key);
    }

    void printTree() {
        inputTreeInverse(root);
        cout << endl;
    }

    bool search(int key) {
        return searchTree(root, key) != nullptr;
    }

    void remove(int key) {
        root = deleteTree(root, key);
    }

    queue<int> collectNegatives() {
        queue<int> negativesQueue;
        collectNegatives(root, negativesQueue);
        return negativesQueue;
    }
    
    queue<int> collectPositives() {
        queue<int> positiveQueue;
        collectPositives(root, positiveQueue);
        return positiveQueue;
    }
};

int main() {
    int num, choice = 0, search_num = 0, delete_num = 0;
    
    bool program_run = true;
    
    BinaryTree tree; // making the tree and doublylinked
    DoublyLinkedList double_linked_list_pos;
    DoublyLinkedList double_linked_list_neg;
    Stack single_stack_list;
    cout << "How many elements do you want to add to the tree?: ";
    cin >> num;
    
    while(num == 0){
        cout << "\nNumber cannot be 0. Please choose a different number: ";
        cin >> num;
    }
    
    int elements[num];
    
    cout << "Please enter " << num << " elements: ";
    for (int i = 0; i < num; i++){
        cin >> elements[i];
    }
    for (int element : elements) {
        tree.insert(element);
    }
    
    while (program_run){
        // starting menu
        cout << "\nPress 1 to search for an element in the tree" << endl;
        cout << "Press 2 to delete an element in the tree" << endl;
        cout << "Press 3 to implement negative numbers in the tree as doubly linked list." << endl;
        cout << "Press 4 to implement positive numbers in the tree as doubly linked list." << endl;
        cout << "Press 5 to remove all elements greater than 10 and input them to a stack implemented as a singly linked list." << endl;
        cout << "Press 6 to remove all items from the tree and the stack by printing them on the screen" << endl;
        cout << "Press 7 to exit the program" << endl;
        cin >> choice;
        
        if (choice == 7){ // return
            program_run = false;
            return 0;
        }
        
        if (choice == 1){ // searching
            cout << "Which integer would you like to search for?: ";
            cin >> search_num;
            int searchKey = search_num;
            if (tree.search(searchKey)) {
                cout << searchKey << " is found in the tree" << endl;
            } else {
                cout << searchKey << " is not found in the tree" << endl;
            }
        }
        
        if (choice == 2){ // deleting
            cout << "Which integer would you like to delete?: ";
            cin >> delete_num;
            int deleteKey = delete_num;
            tree.remove(deleteKey);
            cout << "Deleted " << deleteKey << " from the tree" << endl;
            cout << "Tree after deletion: ";
            tree.printTree();
        }
        
        if (choice == 3){ // negatives to doubly linked
            queue<int> negatives = tree.collectNegatives();
            cout << "Doubly linked list with negative numbers: ";
            while (!negatives.empty()) {
                double_linked_list_neg.insert_double(negatives.front());
                negatives.pop();
            }
            double_linked_list_neg.print_double();
            cout << endl;
        }
        
        if (choice == 4){
            queue<int> positives = tree.collectPositives();
            cout << "\nPositive numbers from tree as doubly linked list: ";
            while (!positives.empty()) {
                double_linked_list_pos.insert_double(positives.front());
                positives.pop();
            }
            double_linked_list_pos.print_double();
            cout << endl;
        }
        
        if (choice == 5) { // remove greater than 10, insert to stack single list
            for (int i = 0; i < num; i++) {
                if (elements[i] > 10) {
                    single_stack_list.push(elements[i]);
                    tree.remove(elements[i]);
                }
            }
            cout << "\nTree after removing elements greater than 10: ";
            tree.printTree();
            
            cout << "Elements greater than 10 inserted into the stack: ";
            single_stack_list.print();
        }
        
        if (choice == 6) { // remove all elements from both queue and single list, print on screen.
            
            for (int i = 0; i < num; i++) { // delete from tree
                cout << "Element removed from tree: " << elements[i] << endl;
                tree.remove(elements[i]);
            }

            double_linked_list_neg.deleteAll_double();
            double_linked_list_pos.deleteAll_double();
            
           
            cout << "Tree after removing all elements: ";
            tree.printTree();
            
            cout << "Queue after removing all elements: ";
            double_linked_list_pos.print_double();
            double_linked_list_neg.print_double();
        }
    }

    cout << "\n";
    return 0;
}

