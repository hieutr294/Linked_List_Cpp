#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class LinkedList {
public:
  Node *head, *tail;

  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  void pushFront(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  void pushBack(int data) {
    // Prepare node
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    // Check if list is empty then head will be newNode
    if (head == NULL) {
      head = newNode;
      return;
    }

    // Traverse all node to find last node
    tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }

    // Link new node to last node
    tail->next = newNode;
  }

  void insertAfter(int pos, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (pos < 1) {
      cout << "Invalid position" << endl;
    } else if (pos == 1) {
      newNode->next = head;
      head = newNode;
      printList();
    } else {
      Node *currentNode = head;
      Node *prevNode = NULL;
      for (int i = 1; i < pos + 1; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
      }
      newNode->next = currentNode;
      prevNode->next = newNode;
      printList();
    }
  }

  void search(int query) {
    Node *temp = head;
    while (temp->next != NULL) {
      if (temp->data == query) {
        cout << temp->data << endl;
        return;
      }
      temp = temp->next;
    }
    cout << "Not found" << endl;
  }

  void printList() {
    Node *temp = head;
    while (temp->next != NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }
    cout << temp->data << endl;
  }
};

int main() {
  LinkedList lst;
  for (int i = 0; i < 6; i++) {
    lst.pushBack(i);
  }
  lst.printList();
}