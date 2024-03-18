//
//  main.cpp
//  algorithms hmwk 1 program 3
//
//  Created by Autumn Tiede on 9/25/23.
//

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
    
    // function for task 3
    void calculateSumAndCount() {
        // check if list empty
            if (!head) {
                std::cout << "The list is empty." << std::endl;
                return;
            }

        // initialize values
            int sumPositive = 0;
            int countNegative = 0;

        // start at head
            Node* current = head;

        // iterate thru data
            while (current) {
                if (current->data > 0) // if value is positive
                    sumPositive += current->data; // add to sum
                else if (current->data < 0) // if value is negative
                    countNegative++; // add to count

                current = current->next;
            }

            std::cout << "\nTask 3: sum of positive members: " << sumPositive << std::endl;
            std::cout << "      number of negative members: " << countNegative << std::endl;
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
    bool program_run = true;
    int choice, N;
    
    while (program_run) {
        
        std::cout << "\n------------- MENU ------------- ";
        std::cout << "\npress 3 to sum the postitive numbers and count the negative numbers  in the list";
        std::cout << "\npress 4 to exit the program";
        std::cout << "\n-------------------------------- " << endl;
        std::cin >>  choice;
        
        // access the list
        LinkedList list;
        
        if (choice == 3){
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
            // access function for task 3
            list.calculateSumAndCount();
        }
        
        else if (choice == 4){
            program_run = false;
        }
    }
    
    cout << "\n";
    return 0;
}
