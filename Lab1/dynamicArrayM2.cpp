#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* arr;             // Pointer to the dynamic array
    size_t leftOffset;     // Offset for the left end
    size_t rightOffset;    // Offset for the right end
    size_t capacity;       // Total capacity of the array

public:
    DynamicArray() : arr(NULL), leftOffset(0), rightOffset(0), capacity(0) {}

    ~DynamicArray() {
        delete[] arr;
    }

    void insertLeft(const T& element) {
        if (leftOffset == 0) {
            // Need to resize the array
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[capacity];
            size_t newRightOffset = capacity - size();
            for (size_t i = 0; i < size(); ++i) {
                newArr[newRightOffset + i] = arr[leftOffset + i];
            }
            delete[] arr;
            arr = newArr;
            leftOffset = newRightOffset;
            rightOffset = capacity - size();
        }
        arr[--leftOffset] = element;
    }

    void insertRight(const T& element) {
        if (rightOffset == 0) {
            // Need to resize the array
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[capacity];
            for (size_t i = 0; i < size(); ++i) {
                newArr[i] = arr[leftOffset + i];
            }
            delete[] arr;
            arr = newArr;
            rightOffset = capacity - size();
        }
        arr[leftOffset + size() + rightOffset++] = element;
    }

    T& operator[](size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return arr[leftOffset + index];
    }

    void print() const {
        for (size_t i = 0; i < size(); ++i) {
            std::cout << arr[leftOffset + i] << " ";
        }
        std::cout << std::endl;
    }

    size_t size() const {
        return leftOffset + rightOffset;
    }
};

int main() {
    DynamicArray<int> dynArray;

    dynArray.insertRight(1);
    dynArray.insertRight(2);
    dynArray.insertLeft(3);
    dynArray.insertLeft(4);
    dynArray.insertRight(5);

    dynArray.print();

    return 0;
}