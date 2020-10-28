#ifndef DISCUSSIONLIST_CPP 
#define DISCUSSIONLIST_CPP
#include "DiscussionTree.h"
#include <iostream>
#include <string>
#include <list>

class DiscussionList {
    public: 
        std::list<DiscussionTree*> _discussionList;

        DiscussionList(){};
        ~DiscussionList(){
            for(auto it =_discussionList.begin();
                    it != _discussionList.end();
                    it++) {
               delete *it; 
            }
        }
        void AddDiscussion(std::string s) {
            DiscussionTree* d = new DiscussionTree(s);
            _discussionList.push_back(d);
        }
        void RemoveDiscussion(Node* n) {
            for(auto it =_discussionList.begin();
                    it != _discussionList.end();
                    it++) {
                if ((*it)->_root == n) {
                    _discussionList.erase(it);
                    delete *it;
                    break;
                }
            }
        }
        void Find(std::string s) {
            for(auto it =_discussionList.begin();
                    it != _discussionList.end();
                    it++) {
                (*it)->PrintDiscussionPath(s);
                std::cout << "\n";
            }
        }
};


#endif
