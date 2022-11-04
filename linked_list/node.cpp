//
//  node.cpp
//  linked_list
//
//  Created by Jakub Prokop on 04.11.2022.
//

#include "node.hpp"
#include <iostream>


Node::Node() {
}

Node::Node(Data d) {
    this->data = d;
    this->next = nullptr;
}

Node::~Node() { 
}
