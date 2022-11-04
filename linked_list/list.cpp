//
//  list.cpp
//  linked_list
//
//  Created by Jakub Prokop on 04.11.2022.
//
/*  notes:
 *      delete keyword can be used in remove methods without new keyword,
 *      because node is created with new
 */

#include "list.hpp"
#include <iostream>

List::List() {
    this->head = nullptr;
    this->tail = nullptr;
    this->ItemCounter = 0;
}

List::~List() {
}

void List::addFirst(Data d) { 
    //if empty, set head and tail at new created node
    if (isEmpty()) {
        Node *p = new Node(d);
        head = p;
        tail = p;
        ItemCounter++;
    //if there is one or more nodes, link newly created node with head, then
    //set newly created node as head (if done conversely, we lose link to linked list)
    } else {
        Node *p = new Node(d);
        p->next = head;
        head = p;
        ItemCounter++;
    }
}

void List::addLast(Data d) {
    if (isEmpty()) {
        addFirst(d);
    //if there is one or more nodes, link newly created node with tail, then
    //set newly created node as tail (if done conversely, we separate tail from the rest)
    } else {
        Node *p = new Node(d);
        tail->next = p;
        tail = p;
        ItemCounter++;
    }
}

void List::removeFirst() {
    if (isEmpty()) {
        return;
    //if there is one or more nodes, use temporary pointer to head,
    //then move head by one node and delete memory stored in temporary pointer
    //(if done conversely, we lose link to node we want to delete)
    } else {
        Node* p = head;
        head = head->next;
        delete p;
        ItemCounter--;
    }
}

void List::removeLast() { 
    if (isEmpty()) {
        return;
    //if there is one or more nodes, we set two pointers,
    //current and previous (pointing to one node back), we move to the end
    //then set tail to node before last one, erase link between these two and delete last node
    } else {
        Node* current = head;
        Node* previous = nullptr;
        while (current != tail) {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = nullptr;
        delete current;
        ItemCounter--;
    }
}

void List::insert(Data d, Data after) {
    if (isEmpty()) {
        return;
    }
    //if there is one or more nodes, we look for node with Data after
    //but till current==nullptr (out of linked list)
    Node* current = head;
    while (current->data != after && current != nullptr) {
        current = current->next;
    }
    //if no match
    if (current == nullptr) {
        std::cout << "Cannot find " << after << " in the list\n";
    //if match is in last node, we must change tail when removing
    } else if (current == tail) {
        addLast(d);
        ItemCounter++;
    //otherwise, we create new node, link newly created node with node after current node
    //(current node is node behind we want to insert the new one)
    //and link current node and newly created node (if done conversely, we lose nodes after current)
    } else {
        Node *p = new Node(d);
        p->next = current->next;
        current->next = p;
        ItemCounter++;
    }
}

void List::remove(Data d) {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return;
    }
    //without special part for head->data = d, it would skip while loop and
    //go to previous->next=current-next case, but since previous=nullptr, nullptr->next give error
    if (head->data == d) {
        removeFirst();
        return;
    }
    Node* current = head;
    Node* previous = nullptr;
    //looking for node with Data d but till current==nullptr (out of linked list)
    while (current->data != d && current != nullptr) {
        previous = current;
        current = current->next;
    }
    //no match, we get to the end of linked list
    if (current == nullptr) {
        std::cout << "Cannot find " << d << " in the list\n";
    //if match is in last node, we must change tail when removing
    } else if (current == tail) {
        previous->next = nullptr;
        tail = previous;
        delete current;
        ItemCounter--;
    //otherwise we link previous node with the one after one we want to delete
    } else {
        previous->next = current->next;
        delete current;
        ItemCounter--;
    }
}

bool List::isEmpty() const {
    return (head == nullptr);
}

void List::print() const {
    std::cout << "   List:\n";
    for (Node *i = head; i != tail->next; i = i->next) {
        std::cout << i->data << "\n";
    }
    std::cout << "   End of list\n";
}


