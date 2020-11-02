#ifndef DISCUSSIONLIST_H 
#define DISCUSSIONLIST_H
#include "DiscussionTree.h"
#include <iostream>
#include <string>
#include <list>

class DiscussionList {
    public: 
        std::list<DiscussionTree*> _discussionList;
        typedef std::list<DiscussionTree*>::iterator iter;

        DiscussionList(){};
        ~DiscussionList();
        void AddDiscussion(std::string s);
        /* void RemoveDiscussion(Node* n); */
        void Find(std::string s);
        bool AddResponse(std::string, std::string, std::string);
        bool DeleteResponse(std::string, std::string);
        void PrintAll();
        bool PrintDiscussion(std::string);
        bool PrintSubDiscussion(std::string, std::string);
};


#endif
