#include <iostream>
using namespace std;

template <typename T>
class Vector {

private:
    size_t size;
    size_t capacity;
    T* data;

public:
    Vector() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }

    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    void resize() {
        capacity = capacity * 2;
        T* new_data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    size_t get_size() {
        return size;
    }

    size_t get_capacity() {
        return capacity;
    }

    bool empty() {
        return size == 0;
    }

    int end() {
        return data[size - 1];
    }
};



int main() {
    Vector <int>  v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);

    cout << "Elements of vector:  {";
    for (int i = 0; i < v.get_size(); ++i) {
        cout << v[i];
        if (v[i] != v.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    cout << "Size of vector: " << v.get_size() << endl;
    cout << "Capacity of vector: " << v.get_capacity() << endl;
}
