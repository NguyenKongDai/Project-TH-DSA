#include<iostream>
#include<string>

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct List{
    Node* head = NULL;
    Node* tail = NULL;
};

void addHead(List &ls, int data){
    if (ls.head == ls.tail){
        Node *newNode = new Node(data);
        newNode->next = ls.head;
        ls.head = newNode;
        ls.tail->next = ls.head;
        return;
    }
    ls.tail->next = new Node(data);
    ls.tail->next->next = ls.head;
    ls.head = ls.tail->next;
}

void addTail(List &ls, int data){
    if (ls.head == ls.tail){
        Node* newNode = new Node(data);
        ls.head->next = newNode;
        ls.tail = newNode;
        ls.tail->next = ls.head;
        return;
    }
    ls.tail->next = new Node(data);
    ls.tail = ls.tail->next;
    ls.tail->next = ls.head;
}

void removeHead(List &ls){
    if (ls.head == ls.tail){
        ls.head = NULL;
        ls.tail = NULL;
        return;
    }
    ls.head = ls.head->next;
    ls.tail->next->next = NULL;
    ls.tail->next = ls.head;
}

void removeTail(List &ls){
    if (ls.head == ls.tail){
        ls.head = NULL;
        ls.tail = NULL;
        return;
    }
    Node * cur = ls.head;
    while (cur->next != ls.tail){
        cur = cur->next;
    }

    ls.tail->next = NULL;
    ls.tail = cur;
    ls.tail->next = ls.head;
}


