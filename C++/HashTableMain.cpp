#include "BST.cpp"
#include "dynArr.cpp"
#include "Hash.cpp"
#include "LinkedList.cpp" 

int main(int argc, char* argv[]) {

    freopen("HashOutput.txt", "w", stdout);

    HashTable table(0);

    for (int i = 0; i < 10; i++) {
        table.insert(rand() % 100);
    }

    table.print();

    table.insert(60);

    table.print();
    
    table.insert(40);

    table.print();

    cout << table.get_num_collisions() << '\n';

    if (table.search(40)) {
        cout << "40 has been found!" << '\n';
    }
    if (table.search(1)) {
        cout << "1 is in the table" << '\n';
    } else {
        cout << "1 is not in the table" << '\n';
    }

    table.put(10, 400);

    table.print();
    
    table.remove(40);

    table.print();

    HashTable table2(1);

    for (int i = 0; i < 10; i++) {
        table2.insert(rand() % 100);
    }

    table2.print();

    table2.insert(60);

    table2.print();
    
    table2.insert(40);

    table2.print();

    cout << table2.get_num_collisions() << '\n';

    if (table2.search(40)) {
        cout << "40 has been found!" << '\n';
    }
    if (table2.search(1)) {
        cout << "1 is in the table" << '\n';
    } else {
        cout << "1 is not in the table" << '\n';
    }

    table2.put(10, 400);

    table2.print();

    table2.remove(40);

    table2.print();

    HashTable table3(2);

    for (int i = 0; i < 10; i++) {
        table3.insert(rand() % 100);
    }

    table3.print();

    table3.insert(60);

    table3.print();
    
    table3.insert(40);

    table3.print();

    cout << table3.get_num_collisions() << '\n';

    if (table3.search(40)) {
        cout << "40 has been found!" << '\n';
    }
    if (table3.search(1)) {
        cout << "1 is in the table" << '\n';
    } else {
        cout << "1 is not in the table" << '\n';
    }

    table3.remove(40);

    table3.print();

    return 0;

}