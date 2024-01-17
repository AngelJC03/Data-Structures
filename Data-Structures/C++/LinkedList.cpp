#include "LinkedList.h"

node::node() {
    this->data = 0;
    this->next = nullptr;
}

node::node(int data) {
    this->data = data;
    this->next = nullptr;
}

node::node(int data, node* next) {
    this->data = data;
    this->next = next;
}

node::~node() {

}

List::List() {
    this->head = nullptr;
    this->size = 0;
}

List::List(int data) {
    this->head = new node(data);
    this->size = 1;
}

List::List(vector<int> numbers) {

    this->head = new node(numbers[0]);

    node* current = head;

    bool firstNum = true;

    for (int i = 1; i < numbers.size(); i++) {
        node* tail = new node(numbers[i]);
        current->next = tail;
        current = current->next;
    }
    this->size = numbers.size();
}

List::~List() {

    node* current = head;

    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}

void List::prepend(int data) {
    node* nuevo = new node(data);
    nuevo->next = head;
    head = nuevo;
    size++;
}

void List::append(int data)
{

    if (head == nullptr) {
        head = new node(data);
        head->next = nullptr;
        size++;
        return;
    }

    node* current = head;
    node* next = current->next;

    while (next != nullptr) {
        current = next;
        next = current->next;
    }

    current->next = new node(data);
    current->next->next = nullptr;
    size++;
}

void List::insert(int data, int index) {

    if (index < 0) {
        cout << "index cannot be a negative integer!!!!" << '\n';
        return;
    }
    if (head == nullptr) {
        cout << "head is a null pointer, setting value to first index." << '\n';
        head = new node(data);
        head->next = nullptr;
        size++;
        return;
    }

    if (index == 0) {
        prepend(data);
    }

    if (index > size) {
        append(data);
    }

    int position = 1;

    node* current = head;

    while (current != nullptr) {
        if (position == index) {
            node* nuevo = new node(data);
            nuevo->next = current->next;
            current->next = nuevo;
            size++;
            return;
        }
        node* next = current->next;
        current = next;
        position++;
    }

}

void List::remove(int data) {
    node* current = head;

    if (current->data == data) {
        node* nuevo = current->next;
        head = nuevo;
        size--;
        return;
    }
    
    while (current->next != nullptr) {
        if (current->next->data == data) {
            node* nuevo = current->next->next;
            current->next = nuevo;
            size--;
            return;
        }
        node* next = current->next;
        current = next;
    }

}

bool List::search(int data) {

    node* current = head;

    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        node* next = current->next;
        current = next;
    }
    return false;
}

int List::getSize()
{
    return this->size;
}

void List::print() {
    node* current = head;

    cout << "Linked List: \n";
    
    while (current != nullptr) {
        node* next = current->next;
        cout << current->data << " next -> ";
        current = next;
    }
    cout << "null \n";
    cout << '\n';
}

void List::clear() {

    while (head != nullptr) {
        node* current = head;
        head = head->next;
        delete current;
    }
}

void List::sort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    head = mergeSort(head);
}

node* List::getMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* List::mergeSort(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    node* left = head;

    node* right = getMid(head);

    node* temp = right->next;
    right->next = nullptr;
    right = temp;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);

}

node* List::merge(node* left, node* right) {
    node* result = new node();

    node* head = result;

    while (left && right) {
        if (left->data < right->data) {
            result->next = left;
            left = left->next;
        }
        else {
            result->next = right;
            right = right->next;
        }
        result = result->next;
    }
    if (left) {
        result->next = left;
    }
    if (right) {
        result->next = right;
    }

    return head->next;
}