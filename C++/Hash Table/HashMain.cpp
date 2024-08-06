#include "Hash.cpp"

int main(int argc, char* argv[]) {

    freopen("HashOutput.txt", "w", stdout);

    HashTable table(0);

    for (int i = 0; i < 10; i++) {
        table.insert(rand() % 100);
    }

    std::cout << "Starting table (Linear Probing): " << '\n';
    table.print();

    std::cout << "**table.insert(60)**" << '\n';
    table.insert(60);

    table.print();
    
    std::cout << "**table.insert(40)**" << '\n';
    table.insert(40);

    table.print();

    std::cout << "**table.get_num_collisions()**" << '\n';
    std::cout << table.get_num_collisions() << "\n\n";

    std::cout << "**table.search(40)**" << '\n';
    if (table.search(40)) {
        std::cout << "40 has been found!" << "\n\n";
    } else {
        std::cout << "40 has not been found!" << "\n\n";
    }

    std::cout << "**table.search(1)**" << '\n';
    if (table.search(1)) {
        std::cout << "1 is in the table" << "\n\n";
    } else {
        std::cout << "1 is not in the table" << "\n\n";
    }

    std::cout << "**table.put(10, 400)**" << '\n';
    table.put(10, 400);
    std::cout << '\n';

    table.print();
    
    std::cout << "**table.remove(40)**" << '\n';
    table.remove(40);

    table.print();

    HashTable table2(1);

    for (int i = 0; i < 10; i++) {
        table2.insert(rand() % 100);
    }

    std::cout << "Starting table (Double Hashing): " << '\n';
    table2.print();

    std::cout << "**table2.insert(60)**" << '\n';
    table2.insert(60);

    table2.print();
    
    std::cout << "**table2.insert(40)**" << '\n';
    table2.insert(40);

    table2.print();

    std::cout << "**table2.get_num_collisions()**" << '\n';
    std::cout << table2.get_num_collisions() << "\n\n";

    std::cout << "**table2.search(40)**" << '\n';
    if (table2.search(40)) {
        std::cout << "40 has been found!" << "\n\n";
    }

    std::cout << "**table2.search(1)**" << '\n';
    if (table2.search(1)) {
        std::cout << "1 is in the table" << "\n\n";
    } else {
        std::cout << "1 is not in the table" << "\n\n";
    }

    std::cout << "**table2.put(10, 400)**" << '\n';
    table2.put(10, 400);
    std::cout << '\n';

    table2.print();

    std::cout << "**table2.remove(40)**" << '\n';
    table2.remove(40);

    table2.print();

    HashTable table3(2);

    for (int i = 0; i < 10; i++) {
        table3.insert(rand() % 100);
    }

    std::cout << "Starting table (Separate Chaining): " << '\n';
    table3.print();

    std::cout << "**table3.insert(60)**" << '\n';
    table3.insert(60);

    table3.print();
    
    std::cout << "**table3.insert(40)**" << '\n';
    table3.insert(40);

    table3.print();

    std::cout << "**table3.get_num_collisions()**" << '\n';
    std::cout << table3.get_num_collisions() << "\n\n";

    std::cout << "**table3.search(40)**" << '\n';
    if (table3.search(40)) {
        std::cout << "40 has been found!" << "\n\n";
    }
    
    std::cout << "**table3.search(1)**" << '\n';
    if (table3.search(1)) {
        std::cout << "1 is in the table" << "\n\n";
    } else {
        std::cout << "1 is not in the table" << "\n\n";
    }

    std::cout << "**table3.remove(40)**" << '\n';
    table3.remove(40);

    table3.print();

    std::cout << "**table3.remove(60)**, removes first instance of 60" << '\n';
    table3.remove(60);

    table3.print();

    return 0;

}
