#include<iostream>
#include<binary_search_tree.h>

using namespace std;

int main() {
    BST t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.Balance();
    t.display(0);
    return 0;
}
