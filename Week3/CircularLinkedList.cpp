#include<iostream>
#include<string>

struct Node{
    int data;
    Node* next = NULL;

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
    ls.tail->next = new Node(data);
    ls.tail->next->next = ls.head;
    ls.head = ls.tail->next;
}

void addTail(List &ls, int data){
    ls.tail->next = new Node(data);
    ls.tail = ls.tail->next;
    ls.tail->next = ls.head;
}

void removeHead(List &ls){
    ls.head = ls.head->next;
    ls.tail->next = ls.head;
}

void removeTail(List &ls){
    Node * cur = ls.head;
    while (cur->next != ls.tail){
        cur = cur->next;
    }

    ls.tail->next = NULL;
    ls.tail = cur;
    ls.tail->next = ls.head;
}

