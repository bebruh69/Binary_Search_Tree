#include<iostream>
#include<binary_search_tree.h>

using namespace std;

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display(0);
    return 0;
}
