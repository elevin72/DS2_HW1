#ifndef DISCUSSIONLIST_H
#define DISCUSSIONLIST_H
#include "DiscussionTree.h"
#include <iostream>
#include <string>
#include <list>

class DiscussionList {
    public: 
        std::list<DiscussionTree> _discussionList;

        DiscussionList(){};
        ~DiscussionList(){};
      
        void AddDiscussion(std::string s);
        void RemoveDiscussion(Node* n);
        void RemoveDiscussion(std::string s);
        void Find(std::string s);
        bool AddResponse(std::string root, std::string parent, std::string child);
        bool DeleteResponse(std::string root, std::string toDelete);
        void PrintAll();
        void PrintFromString(std::string root, std::string);
        bool PrintDiscussion(std::string);
        bool PrintSubDiscussion(std::string, std::string);
};

#endif
