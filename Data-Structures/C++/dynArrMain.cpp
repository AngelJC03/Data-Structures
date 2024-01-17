#include "BST.cpp"
#include "dynArr.cpp"
#include "Hash.cpp"
#include "LinkedList.cpp" 

int main(int argc, char* argv[]) {

    freopen("DynamicArrayOutput.txt", "w", stdout);

    DynArr array;

    for (int i = 0; i < 10; i++) {
        array.push_back(rand() % 100);
    }

    array.print();

    array.removeIndex(4);

    array.print();

    array.removeNum(23);

    array.print();

    array.push_front(10);

    array.print();

    if (array.search(-1)) {
        cout << "found " << -1 << '\n';
    } else {
        cout << "-1 not in array" << '\n';
    } 
    if (array.search(58)) {
        cout << "found 58" << '\n';
    } else {
        cout << "58 not in array" << '\n';
    }

    cout << array.sum() << '\n';

    cout << array.size() << '\n';

    array.sort();

    array.print();

    return 0;
}