#include "DiscussionTree.h"
#include <iostream>
#include <string>
#include <list>

// Note: The _responseList in Node is a list of Node*. If we are iterating through  
//  the list, with an iterator, the proper syntax for accessing members of the Node is:  
//  (*iterator)->member  -- i.e. must be dereferenced twice

int DiscussionTree::count = 0;

DiscussionTree::DiscussionTree() {
    _root = NULL;
    std::cout << ++count << " trees\n";
}


DiscussionTree::DiscussionTree(std::string s) {
    _root = new Node(s);
    std::cout << ++count << " trees\n";
}

DiscussionTree::~DiscussionTree() {
    delete _root;
    std::cout << --count << " trees\n";
}

Node* DiscussionTree::Find(std::string s){
    if(_root->_content.compare(s) == 0) {
        return _root;
    }
    else {
        return Find(s, _root->_responseList);
    }
}

Node* DiscussionTree::Find(std::string s, Node::list& responses) {
    for (Node::list::iterator it = responses.begin(); it != responses.end(); ++it) {
        if ((*it)->_content.compare(s) == 0) { 
            return *it;
       }
       Node* n = Find(s, (*it)->_responseList);
       if (n != NULL) {
           return n;
       }
    }
    return NULL;
}

bool DiscussionTree::AddNode(std::string parentString, std::string childString) {
    Node* parentNode = Find(parentString);
    if (parentNode == NULL) {
       return false; 
    }
    Node* childNode = new Node(childString);
    childNode->_parent = parentNode;
    parentNode->_responseList.push_back(childNode);
    return true;
}

void DiscussionTree::DeleteFromNode(std::string s) {
    Node* n = Find(s);
    if (n == NULL) {
        return;
    }
    n->_parent->_responseList.remove(n); // remove from list
    delete n; // And now delete the element
}

void DiscussionTree::Print(){
    std::cout << _root->_content << "\n";
    Print("   ", _root->_responseList);
}

void DiscussionTree::PrintFromNode(std::string s ){
    Node* n = Find(s);
    if (n == NULL) {
        return;
    }
    std::cout << n->_content << "\n";
    Print("   ", n->_responseList);
    std::cout << "\n";
}

void DiscussionTree::Print(std::string space, Node::list currentList){
    Node::list::iterator end = currentList.end();
    for(Node::list::iterator it = currentList.begin();
            it != end;
            it++) {
        std::cout << space + (*it)->_content << "\n";
        Print(space + "   ", (*it)->_responseList);
    }
}

void DiscussionTree::PrintDiscussionPath(std::string s) {
    Node* n = Find(s);
    while (n != NULL) {
        std::cout << n->_content;
        if (n != _root) {
            std::cout << "=>";
        }
        n = n->_parent;
    } 
    std::cout << "\n";
}

bool DiscussionTree::operator==(DiscussionTree d){
   return ( _root == d._root ); 
}

