#include<iostream>
#include<binary_search_tree.h>

using namespace std;

int main() {
    BST t;
    /* Constructing tree
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
               \
                7         */
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.display(0);
    cout << t.maxhLEFT() << endl << t.minhLEFT() << endl << t.maxhRIGHT() << endl << t.minhRIGHT() << endl;
    if (t.isbalanced())
    {
        cout << "BALANCED" << endl;
    }
    else
    {
        cout << "NOT BALANCED" << endl;
    }
    t.balance();     //balancing tree
    t.display(0);
    cout << t.maxhLEFT() << endl << t.minhLEFT() << endl << t.maxhRIGHT() << endl << t.minhRIGHT() << endl;
    if (t.isbalanced())
    {
        cout << "BALANCED" << endl;
    }
    else
    {
        cout << "NOT BALANCED" << endl;
    }

    return 0;
}
