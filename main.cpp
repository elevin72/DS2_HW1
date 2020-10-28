#include "DiscussionTree.h"

int main(){
    DiscussionTree convo;
    DiscussionTree convo1("OP");
    convo1.AddNode("OP", "Response");
    /* convo1.AddNode("Hello", "Howdy"); */
    /* convo1.AddNode("Hello", "Hai"); */
    convo1.AddNode("Response", "Response2");
    convo1.AddNode("OP", "OtherResponse");
    convo1.Print();
    convo1.DeleteFromNode("Response");
    /* convo1.Find("Partner"); */
    convo1.Print();
    return 0;
}
