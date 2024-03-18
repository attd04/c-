//
//  main.cpp
//  algorithms hmwk 1
//
//  Created by Autumn Tiede on 9/25/23.
//

// 1. Remove the largest and smallest elements from the singly-linked list.

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
    
    // function for task 1
    void removeLargestAndSmallest() {
        // check if list empty or < 1
            if (!head || !head->next) {
                std::cout << "The list is empty or has only one element." << std::endl;
                return;
            }

        // initialize data
            int smallestValue = std::numeric_limits<int>::max();
            int largestValue = std::numeric_limits<int>::min();
            Node* smallest = nullptr;
            Node* largest = nullptr;
            Node* smallestPrev = nullptr;
            Node* largestPrev = nullptr;

            Node* current = head;
            Node* previous = nullptr;

        // finding smallest
            while (current) {
                if (current->data < smallestValue) {
                    smallestValue = current->data;
                    smallest = current;
                    smallestPrev = previous;
                }

                // finding biggest
                if (current->data > largestValue) {
                    largestValue = current->data;
                    largest = current;
                    largestPrev = previous;
                }

                previous = current;
                current = current->next;
            }
        
        // moving head if head = smallest or biggest then removing
            if (smallest) {
                if (smallest == head) {
                    head = head->next;
                } else {
                    smallestPrev->next = smallest->next;
                }
                delete smallest;
            }

            if (largest) {
                if (largest == head) {
                    head = head->next;
                } else {
                    largestPrev->next = largest->next;
                }
                delete largest;
            }
        }
    
    // function for deleting list
    void deleteLinkedList() {
        while (head) {
            Node* temp = head;   // Store the current head node
            head = head->next;  // Move the head to the next node
            delete temp;        // Delete the current node
        }
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
    // access the list
    LinkedList list;
    int N, choice;
    
    bool program_run = true;
    while (program_run) {
        
        std::cout << "------------- MENU ------------- ";
        std::cout << "\npress 1 to remove smallest and largest number from list  ";
        std::cout << "\npress 4 to exit the program";
        std::cout << "\n-------------------------------- " << endl;
        std::cin >>  choice;
        
        int check = 99999;
        int count = 0;

        if (choice == 1){
            bool different_list = false;
            
            while (!different_list){
                // user input for list
                std::cout << "Enter the number of elements: ";
                std::cin >> N;
                std::cout << "Enter " << N << " integers:" << std::endl;
                // put given values in list
                for (int i = 0; i < N; i++) {
                    int num;
                    std::cin >> num;
                    // checking for different values
                    if (num == check){
                        count++;
                    }
                    check = num;
                    
                    list.insert(num);
                }
                
                if (count == N-1){
                    std::cout << "The list needs a variety of elements. Please re enter your list." << "\n" << endl;
                    count = 0;
                    list.deleteLinkedList();
                    different_list = false;
                }
                else {
                    different_list = true;
                }
            }
            
            // access function for task 1
            list.removeLargestAndSmallest();
            std::cout << "\nTask 1: list after removing largest and smallest elements:" << std::endl;
            list.printList();
        }
        
        else if (choice == 4){
            program_run = false;
        }
    }
    
    cout << "\n";
    return 0;
}
