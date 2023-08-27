#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;
    size_t frontOffset;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        size_t oldSize = size;
        for (size_t i = 0; i < oldSize; ++i) {
            newData[newCapacity / 2 - oldSize / 2 + i] = data[frontOffset + i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        frontOffset = newCapacity / 2 - oldSize / 2;
    }

public:
    DynamicArray() : data(NULL), capacity(0), size(0), frontOffset(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    void pushFront(const T& value) {
        if (size == capacity) {
            size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
            resize(newCapacity);
        }
        if (frontOffset == 0) {
            resize(capacity * 2);
        }
        --frontOffset;
        data[frontOffset] = value;
        ++size;
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[size + frontOffset] = value;
        ++size;
    }

    void popFront() {
        if (size > 0) {
            ++frontOffset;
            --size;
            if (size <= capacity / 4 && capacity > 1) {
                resize(capacity / 2);
            }
        }
    }

    void popBack() {
        if (size > 0) {
            --size;
            if (size <= capacity / 4 && capacity > 1) {
                resize(capacity / 2);
            }
        }
    }

    void removeAtIndex(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                data[frontOffset + i] = data[frontOffset + i + 1];
            }
            --size;
            if (size <= capacity / 4 && capacity > 1) {
                resize(capacity / 2);
            }
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    T& operator[](size_t index) {
        if (index < size) {
            return data[frontOffset + index];
        }
        throw std::out_of_range("Index out of bounds");
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    DynamicArray<int> dynArray;

    dynArray.pushBack(1);
    dynArray.pushFront(2);
    dynArray.pushFront(3);
    dynArray.pushBack(4);
    dynArray.pushFront(5);
    dynArray.pushBack(6);

    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    dynArray.popFront();
    dynArray.popBack();
    
    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    dynArray.removeAtIndex(0);
    dynArray.removeAtIndex(2);

    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    return 0;
}
