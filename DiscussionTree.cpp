#ifndef DISCUSSIONTREE_CPP
#define DISCUSSIONTREE_CPP

#include "DiscussionTree.h"
#include <iostream>
#include <string>
#include <list>

/* Note: The _responseList in Node is a list of Node*. If we are iterating through  
 the list, with an iterator, the proper syntax for accessing members of the Node is:  
 (*iterator)->member  -- i.e. must be dereferenced twice*/

DiscussionTree::DiscussionTree() {
    _root = nullptr;
}


DiscussionTree::DiscussionTree(std::string s) {
    Node newNode(s);
    _root = &newNode; // don't believe this works. newNode is local
}

DiscussionTree::~DiscussionTree(){
    delete _root;
}

Node* DiscussionTree::Find(std::string s){
    if(_root->_content.compare(s) == 0){
        return _root;
    }
    else {
        return Find(s, _root->_responseList);
    }
}

Node* DiscussionTree::Find(std::string s, Node::list& responses){
    for (Node::list::iterator it = responses.begin(); it != responses.end(); ++it){
        if ((*it)->_content.compare(s) == 0){ 
            return *it;
       }
       Node* n = Find(s, (*it)->_responseList);
       if (n != nullptr) {
           return n;
       }
    }
    return nullptr;
}

bool DiscussionTree::AddNode(std::string parentString, std::string childString){
    Node* parentNode = Find(parentString);
    if (parentNode == nullptr) {
       return false; 
    }
    Node* childNode = new Node(childString);
    parentNode->_responseList.push_back(childNode);
    parentNode->_responseList.back()->_parent = parentNode;
    return true;
}

void DiscussionTree::DeleteFromNode(std::string s) {
    Node* n = Find(s, _root->_responseList);
    n->_parent->_responseList.remove(n); // remove from list
    delete n; // And now delete the element
}

void DiscussionTree::Print(){
    std::cout << _root->_content << "\n";
    Print("    ", _root->_responseList);
}

void DiscussionTree::PrintFromNode(std::string s ){
    Node* n = Find(s);
    std::cout << n->_content << "\n";
    Print("    ", n->_responseList);
}

void DiscussionTree::Print(std::string space, Node::list currentList){
    for(auto it = currentList.begin();
            it != currentList.end();
            it++) {
        std::cout << space +(*it)->_content << "\n";
        Print(space + "    ", (*it)->_responseList);
    }
}

void DiscussionTree::PrintDiscussionPath(std::string s) {
    Node* n = Find(s);
    do {
        std::cout << n->_content << "=>";
        n = n->_parent;
    } while (n != nullptr);
}

/* bool DiscussionTree::operator==(DiscussionTree  d){ */
/*    return ( _root == d._root ); */ 
/* } */
#endif
