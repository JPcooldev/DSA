//
//  node.hpp
//  linked_list
//
//  Created by Jakub Prokop on 04.11.2022.
//

#ifndef node_hpp
#define node_hpp

#include "data.h"

class Node {
    Data data;
    Node *next;
public:
    Node();
    Node(Data);
    ~Node();
    Data getData() const {return data;}
    void setData(Data d) {data = d;}
    Node* getNext() const {return next;}
    void setNext(Node* n) {next = n;}
    //friend class so List class can access member arguments (i.e. next and data)
    friend class List;
};

#endif /* node_hpp */
