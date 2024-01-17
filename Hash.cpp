
#include "Hash.h"
#include <iostream>
#include <vector>

HashTable::HashTable() {
    this->currentSize = 1;
    this->collisions = 0;  // Initialize collision count
    this->NumElements = 0;
    this->table.resize(this->currentSize);
    this->mode = 2;
}

HashTable::HashTable(int mode) {
    if (mode == 1 || mode == 2) {
        this->currentSize = 1;
        this->NumElements = 0;
        this->collisions = 0;
        this->hashTable = std::vector<int>(this->currentSize, 0);
        this->mode = mode;
    } else {
        this->currentSize = 1;
        this->NumElements = 0;
        this->collisions = 0;  // Initialize collision count
        this->table.resize(this->currentSize);
        this->mode = 2;
        return;
    }
}

HashTable::~HashTable() {

}

int HashTable::hash(int key) {
    return key % this->currentSize;
}

int HashTable::hash2(int key) {
    return (key * key) % this->currentSize;
}

int HashTable::get_num_collisions() {
    return collisions;
}

int HashTable::size() {
    return currentSize;
}

int HashTable::elements() {
    return NumElements;
}

HashTable HashTable::clone() {
    if (mode == 0) {
        HashTable nuevo(0);
        nuevo.hashTable = this->hashTable;
        return nuevo;
    }
    if (mode == 1) {
        HashTable nuevo(1);
        nuevo.hashTable = this->hashTable;
        return nuevo;
    } else {
        HashTable nuevo;
        for (auto bucket : table) {
            for (auto num : bucket) {
                nuevo.insert(num);
            }
        }
        return nuevo;
    }
}

void HashTable::insert(int value) {
    // Check if resizing is needed before insertion
    if (this->mode != 2) {
        if (double(this->NumElements) >= double(this->hashTable.size() * 0.7)) {
            resize();
        }
    }
    if (this->mode == 2) {
        if (double(this->NumElements) >= double(this->table.size() * 0.7)) {
            resize();
        }
    }

    if (this->mode == 0) {
        int index = hash(value);
        if (this->hashTable[index] == 0) {
            this->hashTable[index] = value;
            
        } else {
            while (this->hashTable[index] != 0) {
                index = (index + 1) % this->currentSize;
                this->collisions++;
            }
            this->hashTable[index] = value;
        }
        this->NumElements++;
    }
    else if (this->mode == 1) {
        int c = 0;
        int h1 = hash(value);
        int h2 = hash2(value);
        int index = (h1 + (c + h2)) % this->currentSize;
        if (this->hashTable[index] == 0) {
            this->hashTable[index] = value;
        } else {
            while (this->hashTable[index] != 0) {
                this->collisions++;
                c++;
                index = (h1 + (c + h2)) % this->currentSize;
            }
            this->hashTable[index] = value;
        }
        this->NumElements++;
    }
    else {

        int index = hash(value);
        if (!this->table[index].empty()) {
            this->collisions++;
        }

        table[index].push_front(value);

        table[index].sort();

        this->NumElements++;
    }

    return;
}

bool HashTable::search(int value) {
    if (mode != 2) {
        for (auto num : hashTable) {
            if (num == value) {
                return true;
            }
        }
    } else {
        for (auto chain : table) {
            for (auto num : chain) {
                if (num == value) {
                    return true;
                }
            }
        }
    }
    return false;
}

void HashTable::put(int key, int value) {
    if (mode != 2) {
        int index = hash(key);
        if (hashTable[index] != 0) {
            cout << "Replacing " << hashTable[index] << " with " << value << '\n';
            hashTable[index] = value;
            return;
        } else {
            hashTable[index] = value;
            this->NumElements++;
            return;
        }
    }
    int index = hash(key);

    table[index].push_front(value);

    table[index].sort();

    this->NumElements++;

    return;

}

void HashTable::resize() {
    this->currentSize *= 2;  // Double the size
    std::vector<int> newTable(this->currentSize, 0);
    std::vector<std::list<int> > newTable2(this->currentSize, std::list<int>());

    if (mode == 0) {
        for (int i = 0; i < this->currentSize / 2; ++i) {
            if (this->hashTable[i] != 0) {
                int newIndex = hash(this->hashTable[i]);

                // Handle collisions using linear probing
                while (newTable[newIndex] != 0) {
                    newIndex = (newIndex + 1) % this->currentSize;
                    this->collisions++;
                }

                newTable[newIndex] = this->hashTable[i];
            }
        }
        this->hashTable = std::move(newTable);
        return;
    } 
    
    else if (mode == 1) {
        for (int i = 0; i < (this->currentSize / 2); ++i) {
            if (this->hashTable[i] != 0) {
                int c = 0;
                int h1 = hashTable[i] % (newTable.size());
                int h2 = (hashTable[i] * hashTable[i]) % newTable.size();
                int index = (h1 + (c + h2)) % newTable.size();

                while (newTable[index] != 0) {
                    this->collisions++;
                    h1 = hashTable[i] % (newTable.size());
                    h2 = (hashTable[i] * hashTable[i]) % newTable.size();
                    c++;
                    index = (h1 + (c  + h2)) %  newTable.size();
                    
                }

                newTable[index] = this->hashTable[i];
            }
        }
        this->hashTable = std::move(newTable);
        return;
    }

    else if (mode == 2) {
        std::vector<std::list<int> > newTable2(this->currentSize);

        for (const auto &chain : this->table) {
            for (int value : chain) {
                int newIndex = hash(value);
                if (!newTable2[newIndex].empty()) {
                    this->collisions++;
                }
                newTable2[newIndex].push_back(value);
            }
        }

        this->table = std::move(newTable2);
        return;
    }
}

void HashTable::remove(int key) {
    if (mode != 2) {
        int index = hash(key);
        hashTable[index] = 0;
        this->NumElements -= 1;
        return;
    } else {
        int index = hash(key);
        table[index].clear();
        this->NumElements -= 1;
        return;
    }
}

void HashTable::print()
{
    if (mode == 2) {
        for (int i = 0; i < this->currentSize; i++) {
            std::cout << i << ": ";
            for (auto num : table[i]) {
                cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
     else {
        for (int i = 0; i < this->hashTable.size(); i++) {
            std::cout << i << ": " << this->hashTable[i] << '\n';
        } 
    }
}