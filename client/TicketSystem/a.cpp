#include <iostream>

using namespace std;

struct NODE {
    int data;
    NODE* next;
};

void bubbleSort(NODE* head) {
    bool swapped = true;
    NODE* lastNode = head;

    if(head == NULL) return;

    while(swapped) {
        swapped = false;
        NODE* currentNode = head;

        while(currentNode->next != lastNode) {
            if(currentNode->next->data > currentNode->data) {
                swap(currentNode->next->data, currentNode->data);
                swapped = true;
            }
            currentNode = currentNode->next;
        }
        lastNode = currentNode;
    }
}

int main() {}