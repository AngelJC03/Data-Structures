#include "dynArr.cpp"

int main(int argc, char* argv[]) {

    freopen("DynamicArrayOutput.txt", "w", stdout);

    DynArr array;

    for (int i = 0; i < 10; i++) {
        array.push_back(rand() % 100);
    }

    std::cout << "Starting Array: " << '\n';
    array.print();

    std::cout << "**array.removeIndex(4)**" << '\n';
    array.removeIndex(4);

    array.print();

    std::cout << "**array.removeNum(23)**" << '\n';
    array.removeNum(23);

    array.print();

    std::cout << "**array.push_front(10)**" << '\n';
    array.push_front(10);

    array.print();

    std::cout << "**array.search(-1)**" << '\n';
    if (array.search(-1)) {
        std::cout << "found " << -1 << "\n\n";
    } else {
        std::cout << "-1 not in array" << "\n\n";
    } 

    std::cout << "**array.search(58)**" << '\n';
    if (array.search(58)) {
        std::cout << "found 58" << "\n\n";
    } else {
        std::cout << "58 not in array" << "\n\n";
    }

    std::cout << "**array.sum()**" << '\n';
    std::cout << array.sum() << "\n\n";

    std::cout << "**array.size()**" << '\n';
    std::cout << array.size() << "\n\n";

    std::cout << "**array.sort(), array sorted using quicksort algorithm**" << '\n';
    array.sort();
    array.print();

    return 0;
}