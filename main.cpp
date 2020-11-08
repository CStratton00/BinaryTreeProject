#include <iostream>
#include <string>
#include<fstream>
#include "BinaryTree.h"

using namespace std;

int main() {
    /*
     * input file with text to check
     */
    fstream file("input.in");
    int size;

    /*
     * insert total strings to check against slop
     */
    file >> size;
    string words[size];

    for(int i = 0; !file.eof(); ++i) {
        file >> words[i];
    }
    file.close();

    BinaryTree<string> stringTree;
    for(int i = 0; i < size; i++) {
        stringTree.setheader(stringTree.insert(stringTree.header(), words[i]));
    }
    stringTree.display(stringTree.header()); cout << endl;
    cout << "Tree Height: " << stringTree.getHeight(stringTree.header()) << endl;

    stringTree.search(stringTree.header(), "fish");
    stringTree.deleteNode(stringTree.header(), "fish");
    stringTree.deleteNode(stringTree.header(), "river");
    stringTree.search(stringTree.header(), "fish");

    stringTree.display(stringTree.header()); cout << endl;
    return 0;
}
