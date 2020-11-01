#ifndef DISCUSSIONLIST_CPP
#define DISCUSSIONLIST_CPP
#include "DiscussionList.h"

void DiscussionList::AddDiscussion(std::string s) {
    DiscussionTree d(s);
    _discussionList.push_back(d);
}

void DiscussionList::RemoveDiscussion(Node* n) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end;
            it++) {
        if (it->_root == n) {
            _discussionList.erase(it);
            break;
        }
    }
}

void DiscussionList::RemoveDiscussion(std::string s) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end;
            it++) {
        if (it->_root->_content == s) {
            _discussionList.erase(it);
            break;
        }
    }
}

void DiscussionList::Find(std::string s) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        it->PrintDiscussionPath(s);
        std::cout << "\n";
        it->PrintFromNode(s);
        std::cout << "\n";
    }
}

bool DiscussionList::AddResponse(std::string root, std::string parent, std::string child) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        if (it->_root->_content == root) {
            it->AddNode(parent, child);
            return true;
        }
    } 
    return false;
}

bool DiscussionList::DeleteResponse(std::string root, std::string toDelete) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        if (it->_root->_content == root) {
            it->Delete(toDelete);
            return true;
        }
    }
    return false;
}

void DiscussionList::PrintAll() {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        /* DiscussionTree d = *it; // changed while trying to fix memory issue */
        it->Print();
    }
}

bool DiscussionList::PrintDiscussion(std::string rootString) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        if (it->_root->_content == rootString) {
            it->Print();
            return true;
        }
    }
    return false;
}

bool DiscussionList::PrintSubDiscussion(std::string rootString, std::string toPrint) {
    auto end = _discussionList.end();
    for(auto it =_discussionList.begin();
            it != end; 
            it++) {
        if (it->_root->_content == rootString) {
            it->PrintFromNode(toPrint);
            return true;
        }
    }
    return false;
}

#endif
