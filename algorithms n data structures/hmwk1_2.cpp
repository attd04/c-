//
//  main.cpp
//  algorithms hmwk 1 program 2
//
//  Created by Autumn Tiede on 9/25/23.
//

// 2. Insert the number x before the smallest element in the singly-linked list.
// 3. Enter an integer number N. Enter N integers numbers a1, a2, ... aN into a singly-linked list. In the sequence a1, a2, ... aN calculate and output the sum of the positive members and the number of negative members

#include <iostream>
#include <limits>
using namespace std;

// creating node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} // initializing variables
};

class LinkedList {
private:
    Node* head; // points to first node in list

public:
    LinkedList() : head(nullptr) {}
    // empty constructor & head constructor making head automatically = null

    // function to insert new node in list
    void insert(int val) {
        Node* newNode = new Node(val); // making new node
        if (!head) {
            head = newNode; // putting new node at head
            return;
        }

        // finding last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // put new node at end
        temp->next = newNode;
    }


    void insertBeforeSmallest(int val) {
        // checks if list is empty
        if (!head) {
            std::cout << "\nList is empty. Cannot insert before smallest element." << std::endl;
            return; // if yes return
        }

        // initializing
        Node* current = head;
        Node* smallestPrev = nullptr;
        Node* smallest = head;

        // Find the smallest element and its previous node
        while (current->next) {
            if (current->next->data < smallest->data) { // checks if smaller
                smallest = current->next;
                smallestPrev = current; // keep track of value before smallest
            }

            current = current->next; // iterating
        }

        // create new node for inputting
        Node* newNode = new Node(val);

        if (smallestPrev == nullptr) {
            // if smallest element = head, insert before the head
            newNode->next = head;
            head = newNode;
        } else {
            // insert new node before the smallest element
            newNode->next = smallestPrev->next;
            smallestPrev->next = newNode;
        }

        std::cout << "\nTask 2: modified list after inserting " << val << " before the smallest element:" << std::endl;
        printList(); // prints list
    }

    // function for printing
    void printList() {
        Node* current = head;

        if (current == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    
    int N, choice;
    bool program_run = true;
    
    while (program_run) {
        
        std::cout << "\n------------- MENU ------------- ";
        std::cout << "\npress 2 to insert number x before the smallest element  ";
        std::cout << "\npress 4 to exit the program";
        std::cout << "\n-------------------------------- " << endl;
        std::cin >>  choice;
        
        // access the list
        LinkedList list;
        
        if (choice == 2){
            // user input for list
            std::cout << "Enter the number of elements: ";
            std::cin >> N;
            std::cout << "Enter " << N << " integers:" << std::endl;
            // put given values in list
            for (int i = 0; i < N; i++) {
                int num;
                std::cin >> num;
                list.insert(num);
            }
            // user input for task 2
            int x;
            std::cout << "\nEnter the number to insert before the smallest element: ";
            std::cin >> x;
            // access function for task 2
            list.insertBeforeSmallest(x);
        }
        
        else if (choice == 4){
            program_run = false;
        }
    }
    
    cout << "\n";
    return 0;
}
