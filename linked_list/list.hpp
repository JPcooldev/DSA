//
//  list.hpp
//  linked_list
//
//  Created by Jakub Prokop on 04.11.2022.
//

#ifndef list_hpp
#define list_hpp

#include "node.hpp"

class List {
    Node *head;
    Node *tail;
    int ItemCounter;
    
public:
    List();
    ~List();
    void addFirst(Data d);
    void addLast(Data d);
    void removeFirst();
    void removeLast();
    void insert(Data d, Data after);
    void remove(Data d);
    bool isEmpty() const;
    void print() const;
};

#endif /* list_hpp */
