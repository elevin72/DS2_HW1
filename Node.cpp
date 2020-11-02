#include "Node.h"

Node::Node() { 
    _content = ""; 
    _parent = NULL;
}

Node::Node(std::string content) : _content(content) {
    _parent = NULL; 
}

// go through all nodes that are children to this and delete them as well
// when does 'this' get deleted?
Node::~Node(){  
    list::iterator end = _responseList.end();
    for(list::iterator it = _responseList.begin();
            it != end; 
            it++) {
        delete (*it);
    }
}

bool Node::operator==(Node n){ 
    return (this->_content.compare(n._content));
}
