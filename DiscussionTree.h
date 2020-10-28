// TODO: add error handling?
#ifndef DISCUSSIONTREE_H
#define DISCUSSIONTREE_H

#include <string>
#include "Node.h"
class DiscussionTree {

    public: 
        //typedef Node::list::iterator it;
        Node* _root;
         
        DiscussionTree(); 
        DiscussionTree(std::string);
        Node* Find(std::string s);
        bool AddNode(std::string, std::string); // false if first string does not exist
        void DeleteFromNode(std::string);
        void Print();
        void PrintDiscussionPath(std::string);
        void PrintFromNode(std::string);
        bool operator==(DiscussionTree  d);
        ~DiscussionTree();
    private: 
        Node* Find(std::string s, Node::list& responses);
        void DeleteFromList(Node::list toDelete);
        bool StringCompare(std::string s1, std::string s2);
        void Print(std::string, Node::list currentList);


};
#endif
