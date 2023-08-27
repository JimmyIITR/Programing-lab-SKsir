#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() : data(NULL), capacity(0), size(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[size] = value;
        ++size;
    }

    void popBack() {
        if (size > 0) {
            --size;
            if (size <= capacity / 4 && capacity > 1) {
                size_t newCapacity = capacity / 2;
                resize(newCapacity);
            }
        }
    }

    void removeAtIndex(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
            if (size <= capacity / 4 && capacity > 1) {
                size_t newCapacity = capacity / 2;
                resize(newCapacity);
            }
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    T& operator[](size_t index) {
        if (index < size) {
            return data[index];
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
    dynArray.pushBack(2);
    dynArray.pushBack(3);
    dynArray.pushBack(4);
    dynArray.pushBack(5);

    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    dynArray.popBack();
    dynArray.popBack();

    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;
   dynArray.removeAtIndex(0);

    for (size_t i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    return 0;
}
