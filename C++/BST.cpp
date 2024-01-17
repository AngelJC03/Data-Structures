#include "BST.h"

Node::Node() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int value) {
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {

}

BST::BST() {
    this->root = new Node();
}

BST::BST(int value) {
    this->root = new Node(value);
}

BST::BST(vector<int> items) {
    this->root = new Node(items[0]);
    for (int i = 1; i < items.size(); i++) {
        insert(items[i]);
    }
}

BST::~BST() {

}

void BST::insert(int value) {
    this->insert(root, value);
}

Node* BST::insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }

    if (root->data < value) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }
    
    return root;
}

void BST::remove(int value) {
    this->remove(root, value);
}

Node *BST::remove(Node *root, int value) {
    if (!root) {
        return root;
    }
    if (root->data == value) {
        Node* temp;
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (root->left && !root->right) {
            temp = root->left;
            delete root;
            return temp;
        }
        if (root->right && ! root->left) {
            temp = root->right;
            delete root;
            return temp;
        }
        if (root->right && root->left) {
            temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }

            root->data = temp->data;
            root->right = remove(root->right, temp->data);

            return root;
        }
    }

    if (root->data < value) {
        root->right = remove(root->right, value);
    } else {
        root->left = remove(root->left, value);
    }
    return root;
}

bool BST::search(int value) {
    return this->search(root, value);
}

Node* BST::search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (root->data < value) {
        return search(root->right, value);
    } else {
        return search(root->left, value);
    }
}

void BST::printPRE() {
    cout << "Binary Search Tree: \n";
    cout << "root: " << root->data << '\n';
    this->printPRE(root);
    cout << '\n';
}

void BST::printPRE(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << ": ";
    if (root->left) {
        cout << root->left->data << ", ";
    } else {
        cout << "nullptr, ";
    }
    if (root->right) {
        cout << root->right->data;
    } else {
        cout << "nullptr";
    }
    cout << '\n';
    printPRE(root->left);
    printPRE(root->right);
}

void BST::printPOST() {
    cout << "Binary Search Tree: \n";
    cout << "root: " << root->data << '\n';
    this->printPOST(root);
    cout << '\n';
}

void BST::printPOST(Node* root) {
    if (!root) {
        return;
    }
    printPOST(root->left);
    printPOST(root->right);
    cout << root->data << " ";
    if (root->left) {
        cout << root->left->data << ", ";
    } else {
        cout << "nullptr, ";
    }
    if (root->right) {
        cout << root->right->data;
    } else {
        cout << "nullptr";
    }
    cout << '\n';
}

void BST::printIN() {
    cout << "Binary Search Tree: \n";
    cout << "root: " << root->data << '\n';
    this->printIN(root);
    cout << '\n';
}

void BST::printIN(Node* root) {
    if (!root) {
        return;
    }
    printIN(root->left);
    cout << root->data << " ";
    if (root->left) {
        cout << root->left->data << ", ";
    } else {
        cout << "nullptr, ";
    }
    if (root->right) {
        cout << root->right->data;
    } else {
        cout << "nullptr";
    }
    cout << '\n';
    printIN(root->right);
}
