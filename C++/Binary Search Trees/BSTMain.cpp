#include "BST.cpp"

int main(int argc, char* argv[]) {

    freopen("BinarySearchTreeOutput.txt", "w", stdout);

    BST tree;

    for (int i = 0; i < 10; i++) {
        tree.insert(rand() % 100);
    }

    std::cout << "Starting Tree: " << '\n';
    tree.printIN();

    std::cout << "**tree.remove(7)**" << '\n';
    tree.remove(7);

    tree.printIN();

    std::cout << "**tree.search(60)**" << '\n';
    if (tree.search(60)) {
        std::cout << "Found " << 60 << "\n\n";
    } else {
        std::cout << 60 << " not found" << "\n\n";
    }

    std::cout << "**tree.search(-1)**" << '\n';
    if (tree.search(-1)) {
        std::cout << "Found " << -1 << "\n\n";
    } else {
        std::cout << -1 << " not found" << "\n\n";
    }

    std::cout << "**tree.search(58)**" << '\n';
    if (tree.search(58)) {
        std::cout << "Found " << 58 << "\n\n";
    }
    else {
        std::cout << 15 << " not found!" << "\n\n";
    }
    std::cout << "\n";

    std::cout << "**tree.insert(-5)**" << '\n';
    tree.insert(-5);

    tree.printIN();

    std::cout << "**tree.remove(0)**" << '\n';
    tree.remove(0);

    tree.printIN();
    

    return 0;
}