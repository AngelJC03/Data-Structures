#include "BST.cpp"
#include "dynArr.cpp"
#include "Hash.cpp"
#include "LinkedList.cpp" 

int main(int argc, char* argv[]) {
    // Redirect stdout to listOutput.txt
    freopen("ListOutput.txt", "w", stdout);

    vector<int> items;

    for (int i = 0; i < 9; i++) {
        items.push_back(rand() % 100);
    }

    List list(items);

    list.print();

    list.remove(7);

    list.print();

    list.remove(73);

    list.print();

    cout << list.getSize() << '\n';

    list.insert(400, 9);

    list.insert(13, 2);

    list.print();

    list.append(11);

    list.prepend(3);

    list.print();

    if (list.search(11)) {
        cout << "11 has been found\n";
    } else {
        cout << "no 11 in the list\n";
    }
    if (list.search(1)) {
        cout << "1 has been found\n";
    } else {
        cout << " 1 is not in the list\n";
    }

    list.sort();

    list.print();

    return 0;
}