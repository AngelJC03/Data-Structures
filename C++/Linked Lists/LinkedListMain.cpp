#include "LinkedList.cpp" 

int main(int argc, char* argv[]) {
    // Redirect stdout to listOutput.txt
    freopen("ListOutput.txt", "w", stdout);

    vector<int> items;

    for (int i = 0; i < 9; i++) {
        items.push_back(rand() % 100);
    }

    List list(items);

    std::cout << "Starting List: " << '\n';
    list.print();

    std::cout << "**list.remove(7)**" << '\n';
    list.remove(7);

    list.print();

    std::cout << "**list.remove(73)**" << '\n';
    list.remove(73);

    list.print();

    std::cout << "**list.getSize()**" << '\n';
    std::cout << list.getSize() << '\n';
    std::cout << '\n';

    std::cout << "**list.insert(400, 9)**, 400 has been inserted at index 9" << '\n';
    list.insert(400, 9);


    list.print();

    std::cout << "**list.insert(13, 2)**, 13 has been inserted at index 2" << '\n';
    list.insert(13, 2);

    list.print();

    std::cout << "**list.append(11)**" << '\n';
    list.append(11);

    list.print();

    std::cout << "**list.prepend(3)**" << '\n';
    list.prepend(3);

    list.print();

    std::cout << "**list.search(11)**" << '\n';
    if (list.search(11)) {
        cout << "11 has been found\n\n";
    } else {
        cout << "no 11 in the list\n\n";
    }
    
    std::cout << "**list.search(1)**" << '\n';
    if (list.search(1)) {
        cout << "1 has been found\n\n";
    } else {
        cout << "1 is not in the list\n\n";
    }

    std::cout << "**list.sort()**, list sorted using mergesort algorithm" << '\n';
    list.sort();
    list.print();

    return 0;
}