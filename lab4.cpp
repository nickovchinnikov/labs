#include <iostream>

class DynamicVector {
private:
    int* elements;
    int size;
    int capacity;

public:
    DynamicVector() {
        capacity = 1;
        size = 0;
        elements = new int[capacity];
    }

    ~DynamicVector() {
        delete[] elements;
    }

    int getSize() const {
        return size;
    }

    void printElements() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    void resize(int newCapacity) {
        int* newElements = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    void pushBack(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        elements[size] = value;
        ++size;
    }

    void pushFront(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > 0; --i) {
            elements[i] = elements[i - 1];
        }
        elements[0] = value;
        ++size;
    }

    void removeAt(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            --size;
            if (size < capacity / 2) {
                resize(capacity / 2);
            }
        }
    }
};

int main() {
    DynamicVector vector;

    vector.pushBack(10);
    vector.pushBack(20);
    vector.pushBack(30);

    vector.printElements(); // Output: 10 20 30

    vector.pushFront(5);

    vector.printElements(); // Output: 5 10 20 30

    vector.removeAt(2);

    vector.printElements(); // Output: 5 10 30

    int size = vector.getSize();
    std::cout << "Number of elements: " << size << std::endl; // Output: Number of elements: 3

    return 0;
}
