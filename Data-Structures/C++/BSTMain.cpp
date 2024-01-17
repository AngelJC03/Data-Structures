#include "BST.cpp"
#include "dynArr.cpp"
#include "Hash.cpp"
#include "LinkedList.cpp" 

int main(int argc, char* argv[]) {

    freopen("BinarySearchTreeOutput.txt", "w", stdout);

    BST tree;

    for (int i = 0; i < 10; i++) {
        tree.insert(rand() % 100);
    }

    tree.printIN();

    tree.remove(7);

    tree.printIN();

    if (tree.search(60)) {
        cout << "Found " << 60 << '\n';
    } else {
        cout << 60 << " not found" << '\n';
    }
    if (tree.search(-1)) {
        cout << "Found " << -1 << '\n';
    } else {
        cout << -1 << " not found" << '\n';
    }
    if (tree.search(58)) {
        cout << "Found " << 58 << '\n';
    }
    else {
        cout << 15 << " not found!" << '\n';
    }
    cout << '\n';

    tree.insert(-5);

    tree.printIN();

    tree.remove(0);

    tree.printIN();

    

    return 0;
}