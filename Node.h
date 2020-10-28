// Before submission move function definitions over to Node.cpp
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <list>

class Node {
    public:
        typedef std::list<Node> list;

        //fields
        list _responseList;
        Node* _parent; 
        std::string _content;

        //methods
        static int nodeCount;
        Node(){ _content = ""; 
            _parent = nullptr;
            std::cout << ++nodeCount << "\n";
        }
        Node(std::string content) : _content(content) {
            _parent = nullptr; 
            std::cout << ++nodeCount << "\n";
        }
        ~Node(){
            std::cout << --nodeCount << "\n";
        }
        bool operator==(Node n){ return (this->_content.compare(n._content)); }
        std::string GetContent(){return _content; }
    private:
};

#endif
