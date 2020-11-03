// Eli Levin 341318228
// Data Structures 2 : HW1 : Discussion Trees
// Assignment : Build a discussion forum type structure where discussions can be
// started and responses can me made to those discussions

#include <iostream>
#include <list>
#include <string>
#include "DiscussionList.h"
using namespace std;

int main()
{
    DiscussionList tl;
    string title, father, val, son;
    char ch;
    cout << "\nDISCUSSION TREE\n";
    cout << "Choose one of the following:" << endl;
    cout << "n: New discussion tree" << endl;
    cout << "s: Add a new response" << endl;
    cout << "d: Delete a sub-discussion" << endl;
    cout << "p: Print all discussion trees" << endl;
    cout << "r: Print a sub-tree" << endl;
    cout << "w: Search a string in all discussion trees" << endl;
    cout << "e: exit:" << endl;
    do {
        cin >> ch;
        switch (ch)
        {
            case 'n': cout << "enter the discussion title (with no space) ";
                      cin >> val;
                      tl.AddDiscussion(val);
                      break;
            case 's': cout << "enter the discussion title (with no space) ";
                      cin >> title; 
                      cout << "enter the last message (with no space) ";
                      cin >> father;
                      cout << "enter the new respond ";
                      cin >> son;
                     if (tl.AddResponse(title, father, son)) {
                         cout << "success\n";
                     }
                     else {
                        cout << "ERROR\n";
                     } 
                     break; 
            case 'd': cout << "enter the discussion title (with no space) ";
                      cin >> title; 
                      cout << "enter string of subtree to delete (with no space) ";
                      cin >> val;
                      if (tl.DeleteResponse(title, val)) {
                          cout << "success\n";  
                      }
                      else {
                          cout << "ERROR\n";
                      }
                      break;
            case 'p': tl.PrintAll();
                      break;
            case 'r': cout << "enter the discussion title (with no space) ";
                      cin >> title;
                      cout << "enter the last message (with no space) ";
                      cin >> val;
                      tl.PrintSubDiscussion(title, val);
                      cout << endl;
                      break;
            case 'w': cout << "enter a string (with no space) ";
                      cin >> val; 
                      tl.Find(val);
                      cout << endl;
                      break;
            case 'e': cout << "bye ";
                      break;
            default: cout << "ERROR\n";
                     break;
        }
    } while (ch != 'e');
}

/* TESTS - The instructions don't explain how they want the spacing and newlines, and moodle is being ridiculous
 * Here you can see my prgogram working as intended 
 * I excluded all the lines of adding responses and just showed actual manipulations
 *
 * Demonstrate delete
p
Tree #1
title3
   t3
      t4
      t5

Tree #2
title2
   t2

Tree #3
title1
   t1
   t3

d
enter the discussion title (with no space) title3
enter string of subtree to delete (with no space) t4
success
d
enter the discussion title (with no space) title1
enter string of subtree to delete (with no space) title1
success
p
Tree #1
title3
   t3
      t5

Tree #2
title2
   t2
*/

/* Demonstrate r command
 
p
Tree #1
title3
   t3
      t4
      t5

Tree #2
title2
   t2

Tree #3
title1
   t1

r 
enter the discussion title (with no space) title3
enter the last message (with no space) t3
t3
   t4
   t5
t3=>title3
 */
/*
 * Demonstrate w command
 p
Tree #1
title3
   t3
      t4
      t5

Tree #2
title2
   t2

Tree #3
title1
   t1
   t3

w
enter a string (with no space) t3
t3
t3=>title1

t3
   t4
   t5
t3=>title3
 */
