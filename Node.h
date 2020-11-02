#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <list>

class Node {
    public:
        typedef std::list<Node*> list;

        //fields
        list _responseList;
        Node* _parent; 
        std::string _content;

        //methods
        Node();
        Node(std::string content);
        ~Node();
        bool operator==(Node);
};

#endif
