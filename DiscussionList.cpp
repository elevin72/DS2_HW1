#include "DiscussionList.h"
#include <iostream>

DiscussionList::~DiscussionList(){
    for(iter it =_discussionList.begin();
            it != _discussionList.end();
            it++) {
        delete *it; 
    }
}

void DiscussionList::AddDiscussion(std::string s) {
    DiscussionTree* d = new DiscussionTree(s);
    _discussionList.push_back(d);
}


// was requested in the assignment, but never called so I commented it out
// void DiscussionList::RemoveDiscussion(Node* n) {
//     for(iter it =_discussionList.begin();
//             it != _discussionList.end();
//             it++) {
//         if ((*it)->_root == n) {
//             _discussionList.erase(it);
//             delete *it;
//             break;
//         }
//     }
// }

void DiscussionList::Find(std::string s) {
    for(iter it =_discussionList.begin();
            it != _discussionList.end();
            it++) {
        (*it)->PrintFromNode(s);
        (*it)->PrintDiscussionPath(s);
        std::cout << "\n";
    }
}

bool DiscussionList::AddResponse(std::string root, std::string parent, std::string child) {
    iter end = _discussionList.end();
    for(iter it =_discussionList.begin();
            it != end; 
            it++) {
        if ((*it)->_root->_content == root) {
            return ( (*it)->AddNode(parent, child) );
        }
    } 
    return false;
}

bool DiscussionList::DeleteResponse(std::string rootString, std::string toDelete) {
    std::list<DiscussionTree*>::reverse_iterator end = _discussionList.rend();
    for(std::list<DiscussionTree*>::reverse_iterator it =_discussionList.rbegin();
            it != end; 
            it++) {
        if ((*it)->_root->_content == rootString) {
            if ((*it)->_root->_content == toDelete) { // if the node to delete is a root
                DiscussionTree* dt = *it;
                _discussionList.remove(dt);
                delete dt; 
            }
            else {
                (*it)->DeleteFromNode(toDelete);
            }
        }
        return true; // whether it was root or not, we still succesfully deleted something
    }
    return false;
}

void DiscussionList::PrintAll() {
    int count = 1;
    std::list<DiscussionTree*>::reverse_iterator end = _discussionList.rend();
    for(std::list<DiscussionTree*>::reverse_iterator it =_discussionList.rbegin();
            it != end; 
            it++) {
        std::cout << "Tree #" << count++ << "\n";
        (*it)->Print();
        std::cout << "\n";
    }
}

bool DiscussionList::PrintDiscussion(std::string rootString) {
    iter end = _discussionList.end();
    for(iter it =_discussionList.begin();
            it != end; 
            it++) {
        if ((*it)->_root->_content == rootString) {
            // only print if rootString actually belongs to a root
            (*it)->Print();
            return true;
        }
    }
    return false;
}

bool DiscussionList::PrintSubDiscussion(std::string rootString, std::string toPrint) {
    iter end = _discussionList.end();
    for(iter it =_discussionList.begin();
            it != end; 
            it++) {
        if ((*it)->_root->_content == rootString) {
            (*it)->PrintFromNode(toPrint);
            (*it)->PrintDiscussionPath(toPrint);
            return true;
        }
    }
    return false;
}

